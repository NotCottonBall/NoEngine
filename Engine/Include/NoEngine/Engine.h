#pragma once

#include "Engine/Window.h"
#include "Renderer/Vulkan/VulkanInstance.h"

// @TEMP: We need our own event class
#include <SDL3/SDL_events.h>

namespace NoEngine
{
class Engine
{
public:
  Engine();
  ~Engine();

  void Run();

private:
  void Init();
  void ProcessEvents();

private:
  static Engine* s_Engine;

  // @TEMP: as said, we need our own event class
  SDL_Event m_Event;

  std::unique_ptr<Window> m_Window;
  std::unique_ptr<NoRender::VulkanInstance> m_VulkanInstance;

  bool m_IsRunning;
};
} // namespace NoEngine