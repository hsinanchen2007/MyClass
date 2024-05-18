#pragma once

#ifdef     _DLL_EXPORT
#define     DLL_API   _declspec(dllexport)
#else
#define     DLL_API   _declspec(dllimport)
#endif


DLL_API   void  fun();