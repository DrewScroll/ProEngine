/**********************************************************************************************







***********************************************************************************************/

#pragma once

#define PRO_PLATFORM_WIN32 1 //Windows Platform
#define PRO_PLATFORM_LINUX 2 //Linux Platform

#define PRO_COMPILER_MSVC  1 // Visual Studio Compiler 
#define PRO_COMPILER_GNUC  2 // GCC Compiler

#define PRO_ARCHITECTURE_X86_32 1 //intel x86 32 bits
#define PRO_ARCHITECTURE_X86_64 2 //intel x86 64 bits

#define PRO_ENDIAN_LITTLE 1 //little Endian
#define PRO_ENDIAN_BIG 2  // Big Endian

#define PRO_ENDIAN PRO_ENDIAN_LITTLE // Actual Endian type

<<<<<<< HEAD
#define PRO_LIB_STL 0 //Standard Template Library
#define PRO_LIB_EASTL 1 //Electronic Arts Standard Template Library

#define PRO_LIB_USING PRO_LIB_STL //Which Library we are using
=======
#define PRO_LIB_STL 0 // Standard Template Library
#define PRO_LIB_EASTL 1 // Electronic Arts Library

#define PRO_LIB_USING PRO_LIB_STL // Which Library we are using. 
>>>>>>> edcc2e013d18047535ffeb7599dc357a47993e19

#define PRO_VERSION_MAJOR 0  // Engine Version Mayor Value
#define PRO_VERSION_MINOR 1  // Engine Version Minor Value
#define PRO_VERSION_PATCH 0  // Engine Version Patch Value

// Defines if on a crash we want to report warnings on unknown symbols
#define PRO_DEBUG_DETAILED_SYMBOLS 1

//////////////////////////////
// Compiler Type and version


#if defined (__GNUC__)
#define PRO_COMPILER PRO_COMPILER_GNUC
#define PRO_COMP_VER (((__GNUC__)*100)+(__GNUC_MINOR__*10)+__GNUC_PATCHLEVEL_)
#define PRO_THREADLOCAL __tread
#define PRO_STDCALL __attribute__((stdcall))
#define PRO_CDECL __attribute__((cdecl))
#define PRO_FALLTHROUGH __attribute__((fallthrough))
#elif defined (_MSC_VER)
#define PRO_COMPILER PRO_COMPILER_MSVC
#define PRO_COMP_VER _MSC_VER
#define PRO_THREADLOCAL __declspec(thread)
#define PRO_STDCALL __stdcall
#define PRO_CDECL __cdecl
#define PRO_FALLTHROUGH
#undef __PRETTY_FUNCTION__
#define __PRETTY_FUNCTION__ __FUNCSIG__

#else
// NO known compiler known found.
#pragma error "No known compiler found?!"
#endif



#if PRO_COMPILER == PRO_COMPILER_MSVC // if we are compiling on Visual Studio
# if PRO_COMP_VER >= 1200			  // if we are on visual studio 6 or greater
#   define FORCEINLINE __forceinline  // set __forcedinline
#   ifndef RESTRICT
#     define RESTRICT __restrict	  // No alias hint
#   endif
# endif
#elif defined(__MINGW32__)
# if !defined(FORCEINLINE)
#   define FORCEINLINE __inline
#   ifndef RESTRICT
#     define RESTRICT
#   endif
# endif
#else
# define FORCEINLINE __inline
# ifndef RESTRICT
#   define RESTRICT __restrict
# endif
#endif

// finds the current platform

#if defined (__WIN32__) || defined(_WIN32)
# define PRO_PLATFORM PRO_PLATFORM_WIN32
#else 
# define PRO_PLATFORM PRO_PLATFORM_LINUX
#endif

// Finds Arquitecture Type

#if defined(__X86_64__) || defined(_M_X64)
# define PRO_ARCH_TYPE PRO_ARCHITECTURE_X86_64 // IF THIS IS A X64
#else
# define PRO_ARCH_TYPE PRO_ARCHITECTURE_X86_32 // IF THIS IS A X86 COMPILER
#endif // 

// MEMORY ALIGNMENT MACROS

#if PRO_COMPILER == PRO_COMPILER_MSVC
# define MS_ALIGN(n) __declspec(align(n))
# ifndef GCC_PACK
#  define GCC_PACK(n)
# endif
# ifndef GCC_ALIGN
#  define GCC_ALIGN(n)
# endif
#else
# define MS_ALIGN(n)
# define GCC_PACK(n) __attribute__( (packed, aligned(n)) )
# define GCC_ALIGN(n) __attribute__( (aligned(n)) )
#endif

#if PRO_COMPILER == PRO_COMPILER_MSVC
# define _NOEXCEPT noexcept
#elif PRO_COMPILER == PRO_COMPILER_GNUC
# define _NOEXCEPT noexcept
#else
# define _NOEXCEPT
#endif


//Library Export Specifics

#if PRO_PLATFORM == PRO_PLATFORM_WIN32
# if PRO_COMPILER == PRO_COMPILER_MSVC
#   if defined( PRO_STATIC_LIB )
#    define PRO_UTILITY_EXPORT
#   else
#    if defined( PRO_UTILITY_EXPORTS )
#     define PRO_UTILITY_EXPORT __declspec( dllexport )
#    else 
#     define PRO_UTILITY_EXPORT __declspec( dllimport )
#    endif
#   endif
# else
#  if defined( GE_STATIC_LIB )
#   define PRO_UTILITY_EXPORT
#  else
#   if defined (GE_UTILITY_EXPORTS)
#    define PRO_UTILITY_EXPORT __attribute__ ((dllexport))
#   else
#    define PRO_UTILITY_EXPORT __attribute__ ((dllimport))
#   endif
#  endif
# endif
# define PRO_UTILITY_HIDDEN
#else
# define PRO_UTILITY_EXPORT __attribute__ ((visibility ("default")))
# define PRO_UTILITY_HIDDEN __attribute__ ((visibility ("hidden")))
#endif

//DLL export for plugins
#if PRO_PLATFORM == PRO_PLATFORM_WIN32
# if PRO_COMPILER == PRO_COMPILER_MSVC
#  define PRO_PLUGIN_EXPORT __declspec(dllexport)
# else
#  define PRO_PLUGIN_EXPORT __attribute__ ((dllexport))
# endif
# define PRO_UTILITY_HIDDEN 
#else // linux/mac settings
# define PRO_PLUGIN_EXPORT __attribute__ ((visibility ("default")))
#endif


//   Windows Specific Settings

#if PRO_PLATFORM == PRO_PLATFORM_WIN32
# if defined(_DEBUG) || defined(DEBUG)
#  define PRO_DEBUG_MODE 1
# else 
#  define PRO_DEBUG_MODE 0
# endif
#endif


// LINUX / APPPLE SPECIFIC SETTINGS

#if PRO_PLATFORM == PRO_PLATFORM_LINUX
# define stricmp strcasecmp
# if defined(_DEBUG) || defined(DEBUG)
#  define PRO_DEBUG_MODE 1
# else 
#  define PRO_DEBUG_MODE 0
# endif
#endif

#if PRO_DEBUG_MODE
# define PRO_DEBUG_ONLY(x) x
# define PRO_ASSERT(x) assert(x)
#else
# define PRO_DEBUG_ONLY(x) 
# define PRO_ASSERT(x)
#endif

// disable some Compiler warnings

//if Compiling on Studio

#if PRO_COMPILER==PRO_COMPILER_MSVC

# define _CRT_SECURE_NO_WARNINGS

#endif





















