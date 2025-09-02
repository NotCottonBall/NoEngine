#include "NoEngine/Engine.h"
#include "Core/SDLContext.h"
#include "Debug/NoAssert.h"
#include "Renderer/Vulkan/VulkanInstance.h"

// @TODO: instead of this we need our own event class.
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_video.h>

namespace NoEngine
{
Engine* Engine::s_Engine = nullptr;

Engine::Engine() : m_Window(nullptr), m_IsRunning(true)
{
  NO_ENGINE_ASSERT(!s_Engine,
                   std::string("An Instance Of Engine Already Exists. Creating "
                               "Multiple Instances Of Engine Is Not Allowed"),
                   void(););
  s_Engine = this;

  Init();
}
Engine::~Engine() {}

void Engine::Init()
{
  SDLContext::Init();
  m_Window = Window::Create();
  m_VulkanInstance = NoRender::VulkanInstance::Create();
}

void Engine::Run()
{
  while(m_IsRunning)
  {
    ProcessEvents();
  }

  SDL_Quit();
}

void Engine::ProcessEvents()
{
  // NoEvent::Process(&event)
  while(SDL_PollEvent(&m_Event))
  {
    if(m_Event.type == SDL_EVENT_QUIT)
      m_IsRunning = false;
  }
}
}; // namespace NoEngine