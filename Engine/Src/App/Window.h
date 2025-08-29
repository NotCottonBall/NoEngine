#pragma once

#include <memory>
#include <string>

class SDL_Window;

namespace NoEngine
{
typedef struct WindowCreateInfo
{
  std::string Title;
  int Width;
  int Height;
} WindowCreateInfo;

class Window
{
public:
  Window(const WindowCreateInfo& windowInfo);
  ~Window();
  static std::shared_ptr<Window> Create(const WindowCreateInfo& windowInfo);
  void Init();

  /// @brief this function returns an SDL_Window*
  /// so don't use it in places where you dont wanna expose SDL.
  const SDL_Window* Get() const;

private:
  SDL_Window* m_Window{};
  WindowCreateInfo m_WindowInfo;
};
} // namespace NoEngine