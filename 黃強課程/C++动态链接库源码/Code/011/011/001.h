#pragma once


#ifdef  DLL_EXPORT
#define  DLL_API  _declspec(dllexport) 
#else
#define  DLL_API  _declspec(dllimport) 
#endif

//�����������extern 
DLL_API   extern  int   a;