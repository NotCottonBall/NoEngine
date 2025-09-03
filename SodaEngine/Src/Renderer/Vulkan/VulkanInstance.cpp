#include "Renderer/Vulkan/VulkanInstance.h"
#include "Debug/EngineLog.h"
#include "Debug/SDAssert.h"
#include "FixedGlobals.h"

#include <SDL3/SDL_vulkan.h>

#include <print>
#include <unordered_set>

namespace _SDRender
{
VulkanInstance::VulkanInstance()
    : m_ExtensionsCount(0), m_ExtensionProperties(0)
{
  SDDebug::Log::EngineInfo("Creating A Vulkan Instance...");
  CreateApplication();
  CreateInstance();
  ValidateExtensions();
  SDDebug::Log::EngineInfo("Successfully Initialized Vulkan.");
}

VulkanInstance::~VulkanInstance() { vkDestroyInstance(m_VkInstance, nullptr); }

std::unique_ptr<VulkanInstance> VulkanInstance::Create()
{
  return std::make_unique<VulkanInstance>();
}

void VulkanInstance::CreateApplication()
{
  memset(&m_VkAppInfo, 0, sizeof(m_VkAppInfo));
  m_VkAppInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
  m_VkAppInfo.pApplicationName = "No Application";
  m_VkAppInfo.applicationVersion = VK_MAKE_VERSION(0, 0, 0);
  m_VkAppInfo.pEngineName = "Soda Engine";
  m_VkAppInfo.engineVersion = VK_MAKE_VERSION(SDFixedGlobal::Versions::EMajor,
                                              SDFixedGlobal::Versions::EMinor,
                                              SDFixedGlobal::Versions::EPatch);
  m_VkAppInfo.apiVersion = VK_API_VERSION_1_4;
}

void VulkanInstance::CreateInstance()
{
  memset(&m_VkInstanceCreateInfo, 0, sizeof(m_VkInstanceCreateInfo));
  m_VkInstanceCreateInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
  m_VkInstanceCreateInfo.pApplicationInfo = &m_VkAppInfo;

  // Getting Vulkan Extensions Needed By SDL
  uint32_t count = 0;
  char const* const* extNames = SDL_Vulkan_GetInstanceExtensions(&count);
  SDDebug::Log::EngineDebug("Extensions Required By SDL: ");
  for(uint32_t i = 0; i < count; i++)
  {
    SDDebug::Log::EngineDebug("\t{}", extNames[i]);
  }

  m_VkInstanceCreateInfo.enabledExtensionCount = count;
  m_VkInstanceCreateInfo.ppEnabledExtensionNames = extNames;
  m_VkInstanceCreateInfo.enabledLayerCount = 0;

  if(vkCreateInstance(&m_VkInstanceCreateInfo, nullptr, &m_VkInstance) !=
     VK_SUCCESS)
  {
    SD_ENGINE_ASSERT(false, "Failed To Create Vulkan Instance.", void());
  }
}

void VulkanInstance::ValidateExtensions()
{
  vkEnumerateInstanceExtensionProperties(nullptr, &m_ExtensionsCount, nullptr);
  m_ExtensionProperties.resize(m_ExtensionsCount);
  vkEnumerateInstanceExtensionProperties(nullptr, &m_ExtensionsCount,
                                         m_ExtensionProperties.data());

  SDDebug::Log::EngineDebug("Available Extensions: ");
  std::unordered_set<std::string> extensionsSupported;
  for(const auto& extension : m_ExtensionProperties)
  {
    SDDebug::Log::EngineDebug("\t{}", std::string(extension.extensionName));
    extensionsSupported.insert(extension.extensionName);
  }

  SDDebug::Log::EngineInfo("Checking Support For Extensions Needed By SDL...");
  uint32_t sdlExtCount = 0;
  char const* const* extNamesForSDL =
      SDL_Vulkan_GetInstanceExtensions(&sdlExtCount);
  for(uint32_t i = 0; i < sdlExtCount; i++)
  {
    if(extensionsSupported.contains(extNamesForSDL[i]))
      continue;
    SD_ENGINE_ASSERT(false,
                     "Extensions Required By SDL Were Not Found In The "
                     "Supported Extensions List On Your Device",
                     void());
  }
  SDDebug::Log::EngineInfo("Extensions Required By SDL Are Found.");
}
} // namespace _SDRender