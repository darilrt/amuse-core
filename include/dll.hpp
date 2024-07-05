#pragma once

#if defined(__clang__)

#define AMUSE_API

#elif defined(__GNUC__) || defined(__GNUG__)

#ifdef AMUSE_CORE_EXPORT
#define AMUSE_API __attribute__((visibility("default")))
#else
#define AMUSE_API
#endif // AMUSE_CORE_EXPOR

#elif defined(_MSC_VER)

#ifdef AMUSE_CORE_EXPORT
#define AMUSE_API __declspec(dllexport)
#else
#define AMUSE_API __declspec(dllimport)
#endif // AMUSE_CORE_EXPORT

#endif