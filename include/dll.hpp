#pragma once

#if defined(_MSC_VER)
#ifdef AMUSE_CORE_EXPORT
#define AMUSE_API __declspec(dllexport)
#else
#define AMUSE_API __declspec(dllimport)
#endif // AMUSE_CORE_EXPORT
#elif defined(__GNUC__)
#ifdef AMUSE_CORE_EXPORT
#define AMUSE_API __declspec(dllexport)
#else
#define AMUSE_API
#endif // AMUSE_CORE_EXPORT
#else
#define AMUSE_API
#endif
