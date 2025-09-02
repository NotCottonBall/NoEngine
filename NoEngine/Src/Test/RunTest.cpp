#include "Test/RunTest.h"

// Testing Incldues
#include <SDL3/SDL.h>
#include <glm/glm.hpp>
#include <stb_image.h>
#include <vulkan/vulkan.h>

#include <print>
#include <string>

namespace NoTest
{
bool Test()
{
#ifdef NO_Debug
  std::string windowTitlePrefix = "Debug";
#elif NO_DebRelease
  std::string windowTitlePrefix = "DebRelease";
#elif NO_Release
  std::string windowTitlePrefix = "Release";
#elif NO_RelExport
  std::string windowTitlePrefix = "RelExport";
#elif NO_Export
  std::string windowTitlePrefix = "Export";
#else
  std::string windowTitlePrefix = "Unknown";
#endif

  std::println("Testing Libraries: Vulkan, SDL, GLM, STB...");

  // Testing STB
  int x, y, comp;

  std::println("\nTesting STB_Image");
  // creating a fake 1x1 pixel image to test the API
  unsigned char dummy[1] = {255};
  if(stbi_info_from_memory(dummy, 1, &x, &y, &comp) != 0)
  {
    std::println("STB_Image Failed...");
    return false;
  }
  else
    std::println("STB_Image Worked...");

  // Testing Vulkan
  std::println("\nTesting Vulkan Instance Creation...");
  VkInstance vkInstance;
  VkApplicationInfo vkAppInfo = {};
  vkAppInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
  vkAppInfo.pApplicationName = "NoEngine Test";
  vkAppInfo.applicationVersion = VK_MAKE_VERSION(0, 0, 1);
  vkAppInfo.pEngineName = "NoEngine";
  vkAppInfo.engineVersion = VK_MAKE_VERSION(0, 0, 1);
  vkAppInfo.apiVersion = VK_API_VERSION_1_4;

  VkInstanceCreateInfo vkInstanceInfo = {};
  vkInstanceInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
  vkInstanceInfo.pApplicationInfo = &vkAppInfo;

  VkResult instanceCreateResult =
      vkCreateInstance(&vkInstanceInfo, nullptr, &vkInstance);
  if(instanceCreateResult != VK_SUCCESS)
  {
    std::println("Vulkan Instance Failed...");
    return false;
  }
  else
    std::println("Vulkan Instance Worked...");

  // Testing SDL3
  std::println("\nTesting SDL3 Initialization...");
  if(SDL_Init(SDL_INIT_VIDEO))
  {
    std::println("Initialized SDL Video. Now Testing SDL Window Creation... ");
    SDL_Window* window = SDL_CreateWindow(
        std::string("Test Window - " + windowTitlePrefix).c_str(), 800, 600,
        SDL_WINDOW_VULKAN);
    if(!window)
    {
      std::println("SDL Window Failed...");
      SDL_Quit();
      return false;
    }
    else
    {
      std::println("SDL Window Worked...");
      SDL_DestroyWindow(window);
    }
    SDL_Quit();
  }
  else
  {
    std::println("SDL Initialization Failed...");
    return false;
  }

  // Testing GLM
  std::println("\nTesting GLM By Performing Vector Addition...");
  glm::vec3 vecA(0.1f, 0.3f, 0.5f);
  glm::vec3 vecB(1.0f, 1.0f, 1.0f);
  glm::vec3 vecC = vecA + vecB;

  if(vecC == glm::vec3(1.1f, 1.3f, 1.5f))
  {
    std::println(
        "Performing GLM Addition Works Fine So Overall GLM Should Aswell...");
  }
  else
  {
    std::println(
        "Failed To Perform GLM Addition So Something Is Definetly Wrong...");
    return false;
  }

  return true;
}
} // namespace NoTest
