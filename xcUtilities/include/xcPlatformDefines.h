#pragma once

#define XC_PLATFORM_WIN32 1
#define XC_PLATFORM_LINUX 2

#define XC_COMPILER_MSVC  1
#define XC_COMPILER_GNUC  2
#define XC_COMPILER_INTEL 3
#define XC_COMPILER_CLANG 4

#define XC_ARCHITECTURE_x86_32 1
#define XC_ARCHITECTURE_x86_64 2

#define XC_ENDIAN_LITTLE 1
#define XC_ENDIAN_BIG    2

#define XC_VERSION_MAJOR 0
#define XC_VERSION_MINOR 1
#define XC_VERSION_PATCH 0

#define XC_ENDIAN XC_ENDIAN_LITTLE



///COMPILER
#if defined(__clang__)
#   define XC_COMPILER XC_COMPILER_CLANG
#   define XC_COMP_VER __clang_version__
#   define XC_THREADLOCAL __thread
#   define XC_STDCALL __attribute__((stdcall))
#   define XC_CDECL __attribute__((cdecl))
#   define XC_FALLTHROUGH [[clang::fallthrouhg]];
#elif defined(__GNUC__) //check after clang, as clang defines this too
#   define XC_COMPILER XC_COMPILER_GNUC
#   define XC_COMP_VER (((__GNUC__)*100) + (__GNUC__MINOR__*10) + __GNUC_PATCHLEVEL__)
#   define XC_THREADLOCAL __thread
#   define XC_STDCALL __attribute__((stdcall))
#   define XC_CDECL __attribute__((cdecl))
#   define XC_FALLTHROUGH __attribute__((fallthrough));
#elif defined(__INTEL_COMPILER)
#   define XC_COMPILER XC_COMPILER_INTEL
#   define XC_COMP_VER __INTEL_COMPILER
#   define XC_STDCALL __stdcall
#   define XC_CDECL __cdecl
#   define XC_FALLTHROUGH 

/**
  * XC_THREADLOCAL define is down below because intel compiler defines it
  * differently based on platform
  */

//Check after Clang and Intel, we could be building with either whit VS
#elif defined(_MSC_VER) 
#   define XC_COMPILER XC_COMPILER_MSVC
#   define XC_COMP_VER _MSC_VER
#   define XC_THREADLOCAL __declspec(thread)
#   define XC_STDCALL __stdcall
#   define XC_CDECL __cdecl
#   define XC_FALLTHROUGH
#   undef __PRETTY_FUNCTION__
#   define __PRETTY_FUNCTION__ __FUNCSIG__
#
#else
//No know compiler found, send the error to the output (if any)
#   pragma error "No known compiler. "
#endif

#if XC_COMPILER == XC_COMPILER_MSVC     //if we are compiling on visusal studio
# if XC_COMP_VER >= 1200                //if we are on visual studio 6 or higher
#   define FORCEINLINE __forceinline    // set __forceinline
#   ifndef RESTRICT
#     define RESTRICT __restrict        //No alias hint
#   endif
# endif
#elif defined(__MINGW32__)              //if we are on a Unix type system
# if !defined(FORCEINLINE)
#   define FORCEINLINE __inline         //set __inline
#   ifndef RESTRICT
#     define RESTRICT                   //No alias hint
#   endif
# endif
#else
# define FORCEINLINE __inline
# ifndef RESTRICT
#   define RESTRICT __restrict
# endif
#endif

#if defined(__WIN32__) || defined(_WIN32)  //if it is a wiindows platform
# define XC_PLATFORM XC_PLATFORM_WIN32  
#else                                      //will consider it as a linux platform
# define XC_PLATFORM XC_PLATFORM_LINUX 
#endif


#if defined(__x86_64__) || defined(_M_X64) //if this is a x64 compile
# define XC_ARCH_TYPE XC_ARCHITECTURE_x86_64
#else                                      //if it os a x86 compile
# define XC_ARCH_TYPE XC_ARCHITECTURE_x86_32
#endif


//Memory alignment macros
#if XC_COMPILER == XC_COMPILER_MSVC
# define MS_ALIGN(n) __declspec(align(n))
# ifndef GCC_PACK
#   define GCC_PACK(n)
# endif
# ifndef GCC_ALIGN 
#   define GCC_ALIGN(n)
# endif
#elif (XC_COMPILER == XC_COMPILERGNUC)
#define MS_ALIGN(n)
#define GCC_PACK(n)
#define GCC_ALING(n) __attribute__( (__aligned(n)) )
#else
# define MS_ALIGN(n)
# define GCC_PACK(n)  __attribute__( (packed, aligned(n)) )
# DEFINE GCC_ALIGN(n) __attribute__( (__aligned(n)) )
#endif

#if XC_COMPILER == XC_COMPILER_MSVC ||               \
    XC_COMPILER == XC_COMPILER_INTEL ||              \
    XC_COMPILER == XC_COMPILER_GNUC
# define _NOEXCEPT noexcept
#else
# define _NOEXCEPT
#endif


//library export specificd
#if XC_PLATFORM == XC_PLATFORM_WIN32
# if XC_COMPILER == XC_COMPILER_MSVC
#   if defined( XC_STATIC_LIB )
#     define XC_UTILITY_EXPORT
#   else
#     if defined( XC_UTILITY_EXPORTS )
#        define XC_UTILITY_EXPORT __declspec( dllexport )
#     else
#       define XC_UTILITY_EXPORT __declspec( dllimport )
#     endif
#   endif
# else //any other compiler
#   if defined( XC_STATIC_LIB )
#     define XC_UTILITY_EXPORT
#   else
#     if defined( XC_UTILITY_EXPORTS )
#        define XC_UTILITY_EXPORT __attribute__ ((dllexport))
#     else
#       define XC_UTILITY_EXPORT __attribute__((dllimpor))
#     endif
#   endif
# endif
# define XC_UTILITY_HIDDEN
#else //linux/Mac setting
# define XC_UTILITY_EXPORT __attribute__ ((visibility ("default")))
# define XC_UTILITY_HIDDEN __attribute__ ((visibility ("hidden")))
#endif

//DLL export for plug ins
#if XC_PLATFORM == XC_PLATFORM_WIN32
# if XC_COMPILER == XC_COMPILER_MSVC
#   define XC_PLUGIN_EXPORT __declspec( dllexport )
# else 
#   define XC_PLUGIN_EXPORT __attribute__ ((dllexport))
# endif
#else //linux/Mac settings
# define XC_UTILITY_EXPORT __attribute__ ((visibility ("default")))
#endif

//windows specific settings
#if XC_PLATFORM == XC_PLATFORM_WIN32
# if defined(_DEBUG) || defined(DEBUG)
# define XC_DEBUG_MODE 1
# else 
#   define XC_DEBUG_MODE 0 
# endif
# if XC_COMPILER == XC_COMPILER_INTEL
#    define XC_THREADLOCAL __declspec(thread)
# endif
#endif 

//settings specific Linux/apple 
#if XC_PLATFORM == XC_PLATFORM_LINUX 
# define stricmp strcasecmp

//IF we are on a DEBUG build
# if defined(_DEBUG) || defined(DEBUG)
# define XC_DEBUG_MODE 1
# else 
#   define XC_DEBUG_MODE 0 
# endif
# if XC_COMPILER == XC_COMPILER_INTEL
#    define XC_THREADLOCAL __thread
# endif
#endif 


//definitions of debug macros
#if XC_DEBUG_MODE
# define XC_DEBUG_ONLY(x) x
# define XC_ASSERT(x) assert(x)
#else
# define XC_DEBUG_ONLY(x) 
# define XC_ASSERT(x)
#endif