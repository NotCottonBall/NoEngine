#include "Engine/Window.h"
#include "Debug/SDAssert.h"

#include "Debug/EngineLog.h"

#include <SDL3/SDL_video.h>

namespace SDEngine
{
WindowCreateInfo Window::m_WindowInfo = {std::string("Soda Engine"), 800, 600};

Window::Window(const WindowCreateInfo& windowInfo)
{
  SDDebug::Log::EngineInfo("Creating A Window");
  Init();
  SDDebug::Log::EngineInfo("Successfully Created A Window.");
}
Window::~Window() { SDL_DestroyWindow(m_Window); }

std::unique_ptr<Window> Window::Create(const WindowCreateInfo& windowInfo)
{
  return std::make_unique<Window>(windowInfo);
}

void Window::Init()
{
  m_Window = SDL_CreateWindow(m_WindowInfo.Title.c_str(), m_WindowInfo.Width,
                              m_WindowInfo.Height, SDL_WINDOW_VULKAN);
  SD_ENGINE_ASSERT(m_Window,
                   "Failed To Create An SDL Window Because: " +
                       std::string(SDL_GetError()),
                   SDL_DestroyWindow(m_Window));
}

const SDL_Window* Window::Get() const { return m_Window; }

const WindowCreateInfo& Window::GetWindowInfo() const { return m_WindowInfo; }
void Window::SetWindowInfo(WindowCreateInfo& info) { m_WindowInfo = info; }
} // namespace SDEngine