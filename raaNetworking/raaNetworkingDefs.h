#pragma once
#ifndef RAANETWORKINGDEFS
#define RAANETWORKINGDEFS

#ifdef _WIN32
#pragma warning( disable : 4251 )
#pragma warning( disable : 4786 )
#pragma warning( disable : 4503 )
#pragma warning( disable : 4565 )
#pragma warning( disable : 4150 )
#pragma warning( disable : 4800 )
#pragma warning( disable : 4244 )
#pragma warning( disable : 4995 )

#ifdef _STATIC_RAANETWORKING
#define RAANETWORKING_DLL_DEF
#else
#ifdef RAANETWORKING_EXPORTS
#define RAANETWORKING_DLL_DEF __declspec(dllexport)
#else
#define RAANETWORKING_DLL_DEF __declspec(dllimport)
#ifdef _DEBUG
#pragma comment(lib,"raaNetworkingD")
#else
#pragma comment(lib,"raaNetworkingR")
#endif
#endif 
#endif
#else
#define RAANETWORKING_DLL_DEF
#endif

#endif