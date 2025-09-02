#pragma once

#include <format>
#include <string_view>

void __ClientInfoImpl(std::string_view msg);
void __ClientDebugImpl(std::string_view msg);
void __ClientWarnImpl(std::string_view msg);
void __ClientErrorImpl(std::string_view msg);

namespace NoDebug
{
namespace Log
{
template <typename... Args>
static void Info(std::format_string<Args...> fmt, Args&&... args)
{
  __ClientInfoImpl(std::format(fmt, std::forward<Args>(args)...));
}

template <typename... Args>
static void Debug(std::format_string<Args...> fmt, Args&&... args)
{
  __ClientDebugImpl(std::format(fmt, std::forward<Args>(args)...));
}

template <typename... Args>
static void Warn(std::format_string<Args...> fmt, Args&&... args)
{
  __ClientWarnImpl(std::format(fmt, std::forward<Args>(args)...));
}

template <typename... Args>
static void Error(std::format_string<Args...> fmt, Args&&... args)
{
  __ClientErrorImpl(std::format(fmt, std::forward<Args>(args)...));
}
} // namespace Log
} // namespace NoDebug
