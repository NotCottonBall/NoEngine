#include <SDDebug/Log.h>
#include <SDEngine/Engine.h>

#include <print>

int main()
{
  SDDebug::Log::Info("Starting SodaCan...");
  SDEngine::Engine Engine;
  Engine.Run();
}