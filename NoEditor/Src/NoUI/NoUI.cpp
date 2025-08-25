#include "NoUI/NoUI.h"

#include <imgui.h>

#include <print>

namespace NoUI
{
void ImGuiTest()
{
  std::println(
      "\nCant Test All Of ImGui Without Initializing A Context And Window So "
      "Gonna Call A Bunch Of Functions And Hope ImGui Works :)");
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO& io = ImGui::GetIO();
  (void)io;
  io.DisplaySize.x = 10.0f;
  io.DisplaySize.y = 10.0f;
  std::println("ImGui, The Library Linking, Worked.");
}
} // namespace NoUI