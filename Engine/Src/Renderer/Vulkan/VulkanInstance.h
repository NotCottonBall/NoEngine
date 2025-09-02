#pragma once

#include <vulkan/vulkan.h>

#include <memory>
#include <vector>

namespace NoRender
{
class VulkanInstance
{
public:
  VulkanInstance();
  ~VulkanInstance();

  static std::unique_ptr<VulkanInstance> Create();

private:
  void CreateInstance();
  void CreateApplication();
  void ValidateExtensions();

private:
  VkInstance m_VkInstance;
  VkApplicationInfo m_VkAppInfo;
  VkInstanceCreateInfo m_VkInstanceCreateInfo;

  uint32_t m_ExtensionsCount;
  std::vector<VkExtensionProperties> m_ExtensionProperties;
};
} // namespace NoRender