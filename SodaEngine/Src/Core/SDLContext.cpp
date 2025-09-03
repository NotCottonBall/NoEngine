#include "Core/SDLContext.h"
#include "Debug/SDAssert.h"

#include <SDL3/SDL_init.h>

namespace SDEngine
{
void SDLContext::Init()
{
  if(!SDL_Init(SDL_INIT_VIDEO))
  {
    SD_ENGINE_ASSERT(false,
                     std::string("Failed To Initialize SDL_Video. \nReason: " +
                                 std::string(SDL_GetError())),
                     void());
  }
}
} // namespace SDEngine