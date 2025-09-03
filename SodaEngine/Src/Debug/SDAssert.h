#pragma once

#include <print>

#ifdef SD_Debug
#define SD_ENGINE_ASSERT(expr, msg, callback)                                  \
  {                                                                            \
    if(!(expr))                                                                \
    {                                                                          \
      std::println("\033[31mASSERTION CALLED: {}\n\033[0m", msg);              \
      callback;                                                                \
      std::terminate();                                                        \
    }                                                                          \
  }
#elif SD_DebRelease
#define SD_ENGINE_ASSERT(expr, msg, callback)                                  \
  {                                                                            \
    if(!(expr))                                                                \
    {                                                                          \
      std::println("\033[31mASSERTION CALLED: {}\n\033[0m", msg);              \
      callback;                                                                \
      std::terminate();                                                        \
    }                                                                          \
  }
#elif SD_Release
#define SD_ENGINE_ASSERT(expr, msg, callback)                                  \
  {                                                                            \
    if(!(expr))                                                                \
    {                                                                          \
      std::println("\033[31mASSERTION CALLED (AS WARNING): {}\n\033[0m", msg); \
      callback;                                                                \
    }                                                                          \
  }
#else
#define SD_ENGINE_ASSERT(expr, msg, callback)
#endif