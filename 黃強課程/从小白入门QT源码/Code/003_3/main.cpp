#include <windows.h>
#include <stdio.h>


//声明窗口回调函数
LRESULT   CALLBACK  MyWndProc(HWND  hWnd, UINT  uMsg, WPARAM  wParam, LPARAM  lParam);



//WinMain入口函数
int       WINAPI    WinMain(HINSTANCE  hInstance, HINSTANCE  hPreInstance, LPSTR  lpCmdLine, int nCmdShow)
{
//----------------------------------------------------------------------------------------
//设计窗口类

    WNDCLASS  w;

    w.cbClsExtra=0;
    w.cbWndExtra=0;
    w.hbrBackground=(HBRUSH)GetStockObject(WHITE_BRUSH);
    w.hCursor=LoadCursor(NULL,IDC_CROSS);//注意：如果是系统光标，则第一个参数必须是NULL,否则是当前实例句柄
    w.hIcon=LoadIcon(NULL,IDI_INFORMATION);//注意：如果是标准图标，则第一个参数必须是NULL
    w.hInstance=hInstance;
    w.lpfnWndProc=MyWndProc;//自定义窗口回调函数
    w.lpszClassName="HQ";//自定义类名
    w.lpszMenuName=NULL;//表示无菜单
    w.style=CS_HREDRAW|CS_VREDRAW;


//-----------------------------------------------------------------------------------------
//注册窗口类

    if (RegisterClass(&w)==0)
    {
         return   0;
    }

//-----------------------------------------------------------------------------------------
//利用注册的窗口类创建窗口

     HWND  hWnd;
     hWnd=CreateWindow("HQ","我的窗口",WS_OVERLAPPEDWINDOW,100,100,500,300,NULL,NULL,hInstance,NULL);


     if (hWnd==NULL)
     {
         return  0;
     }

//------------------------------------------------------------------------------------------
//显示窗口，更新窗口

     ShowWindow(hWnd,SW_SHOW);
     UpdateWindow(hWnd);

//-----------------------------------------------------------------------------------------
//消息循环

    MSG  m;

    while (GetMessage(&m,NULL,0,0))//此处用NULL表示接收任何窗口的消息
    {
        TranslateMessage(&m);//用于把虚拟码转换为字符消息
        DispatchMessage(&m);
    }


     return 0;


}


//窗口回调函数(即消息处理函数,由系统调用的)
LRESULT   CALLBACK  MyWndProc(HWND  hWnd, UINT  uMsg, WPARAM  wParam, LPARAM  lParam)
{


      switch (uMsg)
      {

      case   WM_LBUTTONDBLCLK:
          MessageBox(hWnd,"鼠标左键双击","提示",MB_OK);
          break;//注意：MSDN中:Only windows that have the CS_DBLCLKS style can receive WM_LBUTTONDBLCLK messages,所以在设计窗口类时必须加入|CS_DBLCLKS


      case   WM_LBUTTONDOWN:
          MessageBox(hWnd,"鼠标左键单击","提示",MB_OK);
          break;


      case   WM_MBUTTONDOWN:
          MessageBox(hWnd,"鼠标中键单击","提示",MB_OK);
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
          sprintf(a,"WM_CHAR消息:  %c ",wParam);
          MessageBox(hWnd,a,"提示",MB_OK);
          break;

     case WM_CREATE:
        //wParam：未用  1Param：包含一个指向CREATESTRUCT数据结构的指针
        //MessageBoxW(hWnd,"由CreateWindow函数发出的消息","提示",MB_OK);
        break;

     case  WM_PAINT:
         {
          PAINTSTRUCT  p;

          HDC hdc=BeginPaint(hWnd,&p);//WM_PAINT 中只能用BeginPaint
          TextOut(hdc,100,100,"这是由WM_PAINT显示的字体!",strlen("这是由WM_PAINT显示的字体!"));
         EndPaint(hWnd,&p);

         } break;


     case WM_CLOSE:
          if (IDYES==MessageBox(hWnd,"确认关闭吗","提示",MB_YESNO))
          {
              PostQuitMessage(0);
          }
          break;



      case WM_QUIT ://由PostQuitMessage(0);
          DestroyWindow(hWnd);
          break;

       //----------------------------------------------------------------------------
       //默认处理
       default :
        return DefWindowProc(hWnd,uMsg,wParam,lParam);//必须的，如果没有相应处理则调用缺省的消息处理函数

      }

}
