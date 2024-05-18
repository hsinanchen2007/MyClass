#include <windows.h>
#include <stdio.h>


//�������ڻص�����
LRESULT   CALLBACK  MyWndProc(HWND  hWnd, UINT  uMsg, WPARAM  wParam, LPARAM  lParam);



//WinMain��ں���
int       WINAPI    WinMain(HINSTANCE  hInstance, HINSTANCE  hPreInstance, LPSTR  lpCmdLine, int nCmdShow)
{
//----------------------------------------------------------------------------------------
//��ƴ�����

    WNDCLASS  w;

    w.cbClsExtra=0;
    w.cbWndExtra=0;
    w.hbrBackground=(HBRUSH)GetStockObject(WHITE_BRUSH);
    w.hCursor=LoadCursor(NULL,IDC_CROSS);//ע�⣺�����ϵͳ��꣬���һ������������NULL,�����ǵ�ǰʵ�����
    w.hIcon=LoadIcon(NULL,IDI_INFORMATION);//ע�⣺����Ǳ�׼ͼ�꣬���һ������������NULL
    w.hInstance=hInstance;
    w.lpfnWndProc=MyWndProc;//�Զ��崰�ڻص�����
    w.lpszClassName="HQ";//�Զ�������
    w.lpszMenuName=NULL;//��ʾ�޲˵�
    w.style=CS_HREDRAW|CS_VREDRAW;


//-----------------------------------------------------------------------------------------
//ע�ᴰ����

    if (RegisterClass(&w)==0)
    {
         return   0;
    }

//-----------------------------------------------------------------------------------------
//����ע��Ĵ����ഴ������

     HWND  hWnd;
     hWnd=CreateWindow("HQ","�ҵĴ���",WS_OVERLAPPEDWINDOW,100,100,500,300,NULL,NULL,hInstance,NULL);


     if (hWnd==NULL)
     {
         return  0;
     }

//------------------------------------------------------------------------------------------
//��ʾ���ڣ����´���

     ShowWindow(hWnd,SW_SHOW);
     UpdateWindow(hWnd);

//-----------------------------------------------------------------------------------------
//��Ϣѭ��

    MSG  m;

    while (GetMessage(&m,NULL,0,0))//�˴���NULL��ʾ�����κδ��ڵ���Ϣ
    {
        TranslateMessage(&m);//���ڰ�������ת��Ϊ�ַ���Ϣ
        DispatchMessage(&m);
    }


     return 0;


}


//���ڻص�����(����Ϣ������,��ϵͳ���õ�)
LRESULT   CALLBACK  MyWndProc(HWND  hWnd, UINT  uMsg, WPARAM  wParam, LPARAM  lParam)
{


      switch (uMsg)
      {

      case   WM_LBUTTONDBLCLK:
          MessageBox(hWnd,"������˫��","��ʾ",MB_OK);
          break;//ע�⣺MSDN��:Only windows that have the CS_DBLCLKS style can receive WM_LBUTTONDBLCLK messages,��������ƴ�����ʱ�������|CS_DBLCLKS


      case   WM_LBUTTONDOWN:
          MessageBox(hWnd,"����������","��ʾ",MB_OK);
          break;


      case   WM_MBUTTONDOWN:
          MessageBox(hWnd,"����м�����","��ʾ",MB_OK);
      break;


      case   WM_MOUSEMOVE:
          {  HDC  hdc=GetDC(hWnd);
            char a[100];
            sprintf(a,"x:%d  ,y:%d",LOWORD(lParam),HIWORD(lParam));
            TextOut(hdc,200,200,"                          ",25);
            TextOut(hdc,200,200,a,strlen(a));
            ReleaseDC(hWnd,hdc);
          }
          break;


      case  WM_CHAR:
          char a[100];
          sprintf(a,"WM_CHAR��Ϣ:  %c ",wParam);
          MessageBox(hWnd,a,"��ʾ",MB_OK);
          break;

     case WM_CREATE:
        //wParam��δ��  1Param������һ��ָ��CREATESTRUCT���ݽṹ��ָ��
        //MessageBoxW(hWnd,"��CreateWindow������������Ϣ","��ʾ",MB_OK);
        break;

     case  WM_PAINT:
         {
          PAINTSTRUCT  p;

          HDC hdc=BeginPaint(hWnd,&p);//WM_PAINT ��ֻ����BeginPaint
          TextOut(hdc,100,100,"������WM_PAINT��ʾ������!",strlen("������WM_PAINT��ʾ������!"));
         EndPaint(hWnd,&p);

         } break;


     case WM_CLOSE:
          if (IDYES==MessageBox(hWnd,"ȷ�Ϲر���","��ʾ",MB_YESNO))
          {
              PostQuitMessage(0);
          }
          break;



      case WM_QUIT ://��PostQuitMessage(0);
          DestroyWindow(hWnd);
          break;

       //----------------------------------------------------------------------------
       //Ĭ�ϴ���
       default :
        return DefWindowProc(hWnd,uMsg,wParam,lParam);//����ģ����û����Ӧ���������ȱʡ����Ϣ������

      }

}
