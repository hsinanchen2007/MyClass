#include <winsock2.h>
#include <tchar.h> //_Tͷ�ļ�
#include <stdio.h>  

#pragma comment(lib,"WS2_32") 

//1.�Զ�����Ϣ
#define     WM_SOCKET      WM_USER+101 


//----------------���ڹ��̺���������������windows��Ϣ------------- 
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);


//������༭����ʾ
HWND  hwndEdit = NULL;//ȫ�ֱ༭����
void AppendEdit(const char * strOutputString, ...);

/*
1.����project->setting->c/c++,��category��ѡ��preprocessor,��processor definitions��ɾ��_CONSOLE,���_WINDOWS

2.����project->setting->Link, ��Projectoptions�н� /subsystem:consoleѡ��Ϊ����/subsystem:windows.
*/
//----------------win32���ڳ���WinMain()����------------------ 
int  WINAPI  WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	WNDCLASS wc;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WindowProc;//���ڴ�����
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);

	HBRUSH  hbrush = CreateSolidBrush(RGB(255, 0, 0));
	//wc.hbrBackground=(HBRUSH)GetStockObject(BLACK_BRUSH); 
	wc.hbrBackground = hbrush;

	wc.lpszMenuName = NULL;
	wc.lpszClassName = _T("Test");
	//---ע�ᴰ����---- 
	RegisterClass(&wc);
	//---��������---- 
	HWND hwnd = CreateWindow(_T("Test"), _T("���ڱ���"), WS_SYSMENU, 300, 100, 600, 400, NULL, NULL, hInstance, NULL);
	if (hwnd == NULL)
	{
		//AppendEdit("�������ڳ���\n");
		return 1;
	}
	//---��ʾ����---- 
	ShowWindow(hwnd, SW_SHOWNORMAL);
	UpdateWindow(hwnd);
	 

	//---��ʼ��socket����----- 
	WSADATA wsaData;
	WORD wVersionRequested = MAKEWORD(2, 2);
	if (WSAStartup(wVersionRequested, &wsaData) != 0)
	{
		AppendEdit("WSAStartup() Failed: %d", WSAGetLastError());
		return 1;
	}

	//1. ���������׽���
	SOCKET s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (s == INVALID_SOCKET)
	{
		AppendEdit("socket() Failed: %d", WSAGetLastError());
		return 1;
	}

	//2.�󶨵�ip��˿�
	sockaddr_in sin;
	sin.sin_family = AF_INET;
	sin.sin_port = htons(8000);
	sin.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	if (bind(s, (sockaddr*)&sin, sizeof(sin)) == SOCKET_ERROR)
	{
		AppendEdit("bind() Failed: %d", WSAGetLastError());
		return 1;
	}


	//3.����
	if (listen(s, 5) == SOCKET_ERROR)
	{
		AppendEdit("listen() Failed: %d", WSAGetLastError());
		return 1;
	}
	else
	{
		AppendEdit("�������״̬��");
	}


	//4.  ��WSAAsyncSelect�������׽���ע����Ϣ������Ϣ�������ӵ���Ϣ֪ͨ
	int ret=WSAAsyncSelect(s, hwnd, WM_SOCKET, FD_ACCEPT | FD_CLOSE);
	if ( ret!= 0)
	{
		AppendEdit("WSAAsyncSelect Failed: %d", WSAGetLastError());
		return 1;
	}
	else
	{
		AppendEdit("WSAAsyncSelect succes��");
	}


	//---��Ϣѭ����������Ϣ���н���---- 
	MSG msg;
	while (GetMessage(&msg, 0, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	 

	return msg.wParam;
}



LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{ 
    //-----�Զ�����Ϣ
	case WM_SOCKET: 
	{
		SOCKET ss = wParam;   //wParam������־�������¼��������׽ӿ� 
		 
		int     error = WSAGETSELECTERROR(lParam); // ������    
		if (error)
		{
			closesocket(ss);
			AppendEdit("%d   �뿪�����ң�", ss);
			return 0;
		} 

		long event = WSAGETSELECTEVENT(lParam); // �¼�    
		switch (event)
		{
			//-----�����ӿͻ���������
		case FD_ACCEPT:
		{
			sockaddr_in Cadd;
			int Cadd_len = sizeof(Cadd);
			SOCKET sClient = accept(ss, (sockaddr*)&Cadd, &Cadd_len);
			if (sClient != INVALID_SOCKET)
			{
				AppendEdit("��ӭ%d����������!", sClient);

				char tmp[64];				sprintf(tmp, "��ӭ%d���������ң�", sClient);				send(sClient, tmp, strlen(tmp), 0);

				//����ͻ���ͨѶ���׽���ע����Ϣ(��ȡ)
				WSAAsyncSelect(sClient, hwnd, WM_SOCKET, FD_READ | FD_CLOSE);
			}
		}  break;


		//-----�����ݿ��Խ���
		case FD_READ:
		{
			char cbuf[256];
			memset(cbuf, 0, 256);
			int cRecv = recv(ss, cbuf, 256, 0);
			if ((cRecv == SOCKET_ERROR&& WSAGetLastError() == WSAECONNRESET) || cRecv == 0)
			{
				AppendEdit("recv  error: %d", WSAGetLastError());
				closesocket(ss);
			}
			else if (cRecv>0)
			{
				AppendEdit("%d   ˵   %s", ss, cbuf);
			}
		}break;

		//----�۹ر����� 
		case  FD_CLOSE:
		{
			closesocket(ss);
		}break;
		}

		
	} break;




	case WM_CLOSE:
		if (IDYES == MessageBox(hwnd, _T("�Ƿ�ȷ���˳���"), _T("��ʾ"), MB_YESNO))
			DestroyWindow(hwnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_CREATE:
		hwndEdit = CreateWindow(L"EDIT", NULL, WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL,
			10, 10, 500, 200, hwnd, (HMENU)1111, ((LPCREATESTRUCT)lParam)->hInstance, NULL);//�����༭��  
		break;

	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
	return 0;
}




void AppendEdit(const char * strOutputString, ...)
{
	char strBuffer[4096] = { 0 };
	va_list vlArgs;
	va_start(vlArgs, strOutputString);
	_vsnprintf(strBuffer, sizeof(strBuffer) - 1, strOutputString, vlArgs);
	va_end(vlArgs);

	strcat_s(strBuffer, "\r\n");

	/* �����������Ϊ��edit��׷���ַ��� */
	SendMessageA(hwndEdit, EM_SETSEL, -2, -1);
	SendMessageA(hwndEdit, EM_REPLACESEL, true, (long)strBuffer);

	/* ���ù��ֵ�ĩβ�������Ϳ��Կ���������Ϣ */
	SendMessageA(hwndEdit, WM_VSCROLL, SB_BOTTOM, 0);
}
