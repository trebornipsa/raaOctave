#pragma once
#ifndef RAADISPLAYSYSTEMDEFS
#define RAADISPLAYSYSTEMDEFS

#ifdef _WIN32
#pragma warning( disable : 4251 )
#pragma warning( disable : 4786 )
#pragma warning( disable : 4503 )
#pragma warning( disable : 4565 )
#pragma warning( disable : 4150 )
#pragma warning( disable : 4800 )
#pragma warning( disable : 4244 )
#pragma warning( disable : 4995 )

#ifdef _STATIC_RAADISPLAYSYSTEM
#define RAADISPLAYSYSTEM_DLL_DEF
#else
#ifdef RAADISPLAYSYSTEM_EXPORTS
#define RAADISPLAYSYSTEM_DLL_DEF __declspec(dllexport)
#else
#define RAADISPLAYSYSTEM_DLL_DEF __declspec(dllimport)
#ifdef _DEBUG
#pragma comment(lib,"raaDisplaySystemD")
#else
#pragma comment(lib,"raaDisplaySystemR")
#endif
#endif 
#endif
#else
#define RAADISPLAYSYSTEM_DLL_DEF
#endif

#endif