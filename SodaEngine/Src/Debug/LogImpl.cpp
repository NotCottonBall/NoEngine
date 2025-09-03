#include "Debug/EngineLog.h"
#include "SDDebug/Log.h"

#include <print>
#include <string_view>

constexpr const char* Color_Green = "\033[32m";
constexpr const char* Color_Blue = "\033[34m";
constexpr const char* Color_Yellow = "\033[33m";
constexpr const char* Color_Red = "\033[31m";
constexpr const char* Color_Reset = "\033[0m";

// Engine Side //
void __EngineInfoImpl(std::string_view msg)
{
  std::println("{}ENGINE_INFO: {}{}", Color_Green, msg, Color_Reset);
}

void __EngineDebugImpl(std::string_view msg)
{
  std::println("{}{}{}", Color_Blue, msg, Color_Reset);
}

void __EngineWarnImpl(std::string_view msg)
{
  std::println("{}ENGINE_WARN: {}{}", Color_Yellow, msg, Color_Reset);
}

void __EngineErrorImpl(std::string_view msg)
{
  std::println("{}ENGINE_ERROR: {}{}", Color_Red, msg, Color_Reset);
}

// Client Side //
void __ClientInfoImpl(std::string_view msg)
{
  std::println("{}INFO: {}{}", Color_Green, msg, Color_Reset);
}

void __ClientDebugImpl(std::string_view msg)
{
  std::println("{}{}{}", Color_Blue, msg, Color_Reset);
}

void __ClientWarnImpl(std::string_view msg)
{
  std::println("{}WARN: {}{}", Color_Yellow, msg, Color_Reset);
}

void __ClientErrorImpl(std::string_view msg)
{
  std::println("{}ERROR: {}{}", Color_Red, msg, Color_Reset);
}