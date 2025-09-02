#pragma once

#include <print>

#ifdef NO_Debug
#define NO_ENGINE_ASSERT(expr, msg, callback)                                  \
  {                                                                            \
    if(!(expr))                                                                \
    {                                                                          \
      std::println("\033[31mASSERTION CALLED: {}\n\033[0m", msg);              \
      callback;                                                                \
      std::terminate();                                                        \
    }                                                                          \
  }
#elif NO_DebRelease
#define NO_ENGINE_ASSERT(expr, msg, callback)                                  \
  {                                                                            \
    if(!(expr))                                                                \
    {                                                                          \
      std::println("\033[31mASSERTION CALLED: {}\n\033[0m", msg);              \
      callback;                                                                \
      std::terminate();                                                        \
    }                                                                          \
  }
#elif NO_Release
#define NO_ENGINE_ASSERT(expr, msg, callback)                                  \
  {                                                                            \
    if(!(expr))                                                                \
    {                                                                          \
      std::println("\033[31mASSERTION CALLED (AS WARNING): {}\n\033[0m", msg); \
      callback;                                                                \
    }                                                                          \
  }
#else
#define NO_ENGINE_ASSERT(expr, msg, callback)
#endif