#pragma once

#include <format>
#include <string_view>

void __EngineInfoImpl(std::string_view msg);
void __EngineDebugImpl(std::string_view msg);
void __EngineWarnImpl(std::string_view msg);
void __EngineErrorImpl(std::string_view msg);

namespace SDDebug
{
namespace Log
{
template <typename... Args>
void EngineInfo(std::format_string<Args...> fmt, Args&&... args)
{
  __EngineInfoImpl(std::format(fmt, std::forward<Args>(args)...));
}

template <typename... Args>
void EngineDebug(std::format_string<Args...> fmt, Args&&... args)
{
  __EngineDebugImpl(std::format(fmt, std::forward<Args>(args)...));
}

template <typename... Args>
void EngineWarn(std::format_string<Args...> fmt, Args&&... args)
{
  __EngineWarnImpl(std::format(fmt, std::forward<Args>(args)...));
}

template <typename... Args>
void EngineError(std::format_string<Args...> fmt, Args&&... args)
{
  __EngineErrorImpl(std::format(fmt, std::forward<Args>(args)...));
}
} // namespace Log
} // namespace SDDebug