#ifndef _DLL_IMPORT_H_
#define _DLL_IMPORT_H_

  #ifdef SANDBOXLIB_EXPORTS  
    #define SANDBOXLIB_API  __declspec(dllexport)  
  #else  
    #define SANDBOXLIB_API __declspec(dllimport)  
  #endif

#endif
