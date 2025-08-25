cmake_minimum_required(VERSION 3.31)
project(NoLibraries)

# Now, this is useful for me because I want seperate output folders for seperate platforms and compilers.
foreach(CONFIG "Debug" "Release")
    string(TOUPPER ${CONFIG} CONFIG_UPPER)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${CONFIG_UPPER}
        "${CMAKE_SOURCE_DIR}/Bin/${CMAKE_SYSTEM_NAME}-${CMAKE_BUILD_TYPE}-${CMAKE_CXX_COMPILER_ID}")
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_${CONFIG_UPPER}
        "${CMAKE_SOURCE_DIR}/Libs/Libraries${CMAKE_SYSTEM_NAME}-${CMAKE_BUILD_TYPE}-${CMAKE_CXX_COMPILER_ID}")
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${CONFIG_UPPER}
        "${CMAKE_SOURCE_DIR}/Libs/${CMAKE_SYSTEM_NAME}-${CMAKE_BUILD_TYPE}-${CMAKE_CXX_COMPILER_ID}")
endforeach()

# Adding Outside Stuff
add_subdirectory(${CMAKE_SOURCE_DIR}/sdl3)
find_package(Vulkan REQUIRED)

# Adding Libraries
add_library(imgui STATIC
  ${CMAKE_SOURCE_DIR}/imgui/imconfig.h
  ${CMAKE_SOURCE_DIR}/imgui/imgui.h
  ${CMAKE_SOURCE_DIR}/imgui/imgui.cpp
  ${CMAKE_SOURCE_DIR}/imgui/imgui_draw.cpp
  ${CMAKE_SOURCE_DIR}/imgui/imgui_internal.h
  ${CMAKE_SOURCE_DIR}/imgui/imgui_tables.cpp
  ${CMAKE_SOURCE_DIR}/imgui/imgui_widgets.cpp
  ${CMAKE_SOURCE_DIR}/imgui/imstb_rectpack.h
  ${CMAKE_SOURCE_DIR}/imgui/imstb_textedit.h
  ${CMAKE_SOURCE_DIR}/imgui/imstb_truetype.h
  ${CMAKE_SOURCE_DIR}/imgui/imgui_demo.cpp

  ${CMAKE_SOURCE_DIR}/imgui/backends/imgui_impl_sdl3.cpp
  ${CMAKE_SOURCE_DIR}/imgui/backends/imgui_impl_vulkan.cpp
)
target_include_directories(imgui PUBLIC
  ${CMAKE_SOURCE_DIR}/imgui
  ${CMAKE_SOURCE_DIR}/sdl3/include
  ${Vulkan_INCLUDE_DIRS}
)

# Disable unused SDL3 subsystems/drivers in CMake
set(SDL_ALSA OFF CACHE BOOL "")
set(SDL_ARTS OFF CACHE BOOL "")
set(SDL_ESD OFF CACHE BOOL "")
set(SDL_NAS OFF CACHE BOOL "")
set(SDL_JACK OFF CACHE BOOL "")
set(SDL_PULSEAUDIO OFF CACHE BOOL "")
set(SDL_SNDIO OFF CACHE BOOL "")
set(SDL_AUDIO OFF CACHE BOOL "")
set(SDL_RENDER OFF CACHE BOOL "")
set(SDL_OPENGL OFF CACHE BOOL "")
set(SDL_DIRECTFB OFF CACHE BOOL "")
set(SDL_WAYLAND OFF CACHE BOOL "")
set(SDL_X11 OFF CACHE BOOL "")
set(SDL_COCOA OFF CACHE BOOL "")
set(SDL_MIR OFF CACHE BOOL "")
set(SDL_RPI OFF CACHE BOOL "")
set(SDL_DUMMYVIDEO OFF CACHE BOOL "")
set(SDL_TEST OFF CACHE BOOL "")
set(SDL_SENSOR OFF CACHE BOOL "")
set(SDL_HIDAPI OFF CACHE BOOL "")
set(SDL_POWER OFF CACHE BOOL "")
set(SDL_TEST OFF CACHE BOOL "")
set(SDL_EXAMPLES OFF CACHE BOOL "")

# Enable Vulkan, windowing, joystick, events, and input related stuff
set(SDL_VULKAN ON CACHE BOOL "")
set(SDL_VIDEO ON CACHE BOOL "")
set(SDL_JOYSTICK ON CACHE BOOL "")
set(SDL_EVENTS ON CACHE BOOL "")
set(SDL_HAPTIC ON CACHE BOOL "")