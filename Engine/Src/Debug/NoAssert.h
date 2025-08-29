#pragma once

#include <print>

#ifdef NO_Debug
#define NO_ENGINE_ASSERT(expr, msg, callback)                                  \
  {                                                                            \
    if(!(expr))                                                                \
    {                                                                          \
      std::println("ASSERTION CALLED: {}\n", msg);                             \
      callback;                                                                \
      std::terminate();                                                        \
    }                                                                          \
  }
#elif NO_DebRelease
#define NO_ENGINE_ASSERT(expr, msg, callback)                                  \
  {                                                                            \
    if(!(expr))                                                                \
    {                                                                          \
      std::println("ASSERTION CALLED: {}\n", msg);                             \
      callback;                                                                \
      std::terminate();                                                        \
    }                                                                          \
  }
#elif NO_Release
#define NO_ENGINE_ASSERT(expr, msg, callback)                                  \
  {                                                                            \
    if(!(expr))                                                                \
    {                                                                          \
      std::println("ASSERTION CALLED AS WARNING: {}\n", msg);                  \
      callback;                                                                \
    }                                                                          \
  }
#else
#define NO_ENGINE_ASSERT(expr, msg, callback)
#endif