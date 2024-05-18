// 063.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <typeinfo>
using namespace std;
#include <afxwin.h>

int main()
{
	const type_info &t = typeid(CWnd);
	cout << t.name() << endl;//打印类名称

	cout << typeid(CString).name() << endl;
	CDialog dlg;//typeid的参数可以是变量或类型
	cout << (typeid(dlg) == typeid(CDialog)) << endl;

	cout << typeid(1 + 100).name() << endl;

	//测试Mfc的运行时类型识别支持
	CWnd wnd;
	cout <<"CWnd IsKindOf CObject     " <<wnd.IsKindOf(RUNTIME_CLASS(CObject))<<endl;
	cout << "CWnd IsKindOf CObject     " << wnd.IsKindOf(CObject::GetThisClass()) << endl;
	cout << "CWnd IsKindOf CWnd     " << wnd.IsKindOf(RUNTIME_CLASS(CWnd)) << endl;
	cout << "CWnd IsKindOf CFrameWnd     " << wnd.IsKindOf(RUNTIME_CLASS(CFrameWnd)) << endl;
	cout << "CWnd IsKindOf CCmdTarget     " << wnd.IsKindOf(RUNTIME_CLASS(CCmdTarget)) << endl;

	return 0;
}

