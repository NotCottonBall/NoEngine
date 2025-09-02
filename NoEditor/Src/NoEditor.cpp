#include <NoDebug/Log.h>
#include <NoEngine/Engine.h>

#include <print>

int main()
{
  NoDebug::Log::Info("Starting The Editor...");
  NoEngine::Engine engine;
  engine.Run();
}