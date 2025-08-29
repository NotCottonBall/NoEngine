#include "App/Window.h"
#include "Debug/NoAssert.h"

#include <SDL3/SDL_video.h>

namespace NoEngine
{
Window::Window(const WindowCreateInfo& windowInfo) : m_WindowInfo(windowInfo)
{
  Init();
}
Window::~Window() { SDL_DestroyWindow(m_Window); }

std::shared_ptr<Window> Window::Create(const WindowCreateInfo& windowInfo)
{
  return std::make_shared<Window>(windowInfo);
}

void Window::Init()
{
  m_Window = SDL_CreateWindow(m_WindowInfo.Title.c_str(), m_WindowInfo.Width,
                              m_WindowInfo.Height, SDL_WINDOW_VULKAN);
  NO_ENGINE_ASSERT(m_Window,
                   "Failed To Create An SDL Window Because: " +
                       std::string(SDL_GetError()),
                   SDL_DestroyWindow(m_Window));
}

const SDL_Window* Window::Get() const { return m_Window; }
} // namespace NoEngine