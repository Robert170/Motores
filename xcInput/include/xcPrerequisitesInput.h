#pragma once

#include "xcPrerequisitesUtilities.h"

//library export specific
#if XC_PLATFORM == XC_PLATFORM_WIN32
# if XC_COMPILER == XC_COMPILER_MSVC
#   if defined( XC_STATIC_LIB )
#     define XC_INPUT_EXPORT
#   else
#     if defined( XC_INPUT_EXPORTS )
#        define XC_INPUT_EXPORT __declspec( dllexport )
#     else
#       define XC_INPUT_EXPORT __declspec( dllimport )
#     endif
#   endif
# else //any other compiler
#   if defined( XC_STATIC_LIB )
#     define XC_INPUT_EXPORT
#   else
#     if defined( XC_INPUT_EXPORT )
#        define XC_INPUT_EXPORT __attribute__ ((dllexport))
#     else
#       define XC_INPUT_EXPORT __attribute__((dllimpor))
#     endif
#   endif
# endif
# define XC_RENDERER_HIDDEN
#else //Linux/Mac setting
# define XC_INPUT_EXPORT __attribute__ ((visibility ("default")))
# define XC_RENDERER_HIDDEN __attribute__ ((visibility ("hidden")))
#endif
