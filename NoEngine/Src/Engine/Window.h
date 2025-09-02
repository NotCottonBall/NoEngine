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
  static std::unique_ptr<Window> Create(
      const WindowCreateInfo& windowInfo = m_WindowInfo);
  void Init();

  /// @brief this function returns an SDL_Window*
  /// so don't use it in places where you dont wanna expose SDL.
  const SDL_Window* Get() const;

  const WindowCreateInfo& GetWindowInfo() const;
  void SetWindowInfo(WindowCreateInfo& info);

private:
  SDL_Window* m_Window;
  static WindowCreateInfo m_WindowInfo;
};
} // namespace NoEngine