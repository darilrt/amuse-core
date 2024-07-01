#pragma once

#if defined(_MSC_VER)
#ifdef DAMUSE_CORE_EXPORT
#define AMUSE_API __declspec(dllexport)
#else
#define AMUSE_API __declspec(dllimport)
#endif // DAMUSE_CORE_EXPORT
#elif defined(__GNUC__)
//  GCC
#ifdef DAMUSE_CORE_EXPORT
#define AMUSE_API __attribute__((visibility("default")))
#else
#define AMUSE_API
#endif // DAMUSE_CORE_EXPORT
#else
#define AMUSE_API
#endif
