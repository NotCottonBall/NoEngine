cmake_minimum_required(VERSION 3.31)
project(NoEngine)

# Settings and Variables
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Settings up the build type
set(CMAKE_CONFIGURATION_TYPES "Debug;DebRelease;Release;RelExport;Export" CACHE STRING "Choose A Build Type (Debug | Release)" FORCE)
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release")
  message("No Build Type Was Selected (No Pun Intended). So Defaulting To Release")
endif()

# Now, this is useful for me because I want seperate output folders for seperate platforms and compilers.
foreach(CONFIG "Debug" "DebRelease" "Release" "RelExport" "Export")
  string(TOUPPER ${CONFIG} CONFIG_UPPER)
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${CONFIG_UPPER}
        "${CMAKE_SOURCE_DIR}/Bin/${CMAKE_SYSTEM_NAME}-${CMAKE_BUILD_TYPE}-${CMAKE_CXX_COMPILER_ID}")
  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_${CONFIG_UPPER}
        "${CMAKE_SOURCE_DIR}/Libs/Libraries${CMAKE_SYSTEM_NAME}-${CMAKE_BUILD_TYPE}-${CMAKE_CXX_COMPILER_ID}")
  set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${CONFIG_UPPER}
        "${CMAKE_SOURCE_DIR}/Libs/${CMAKE_SYSTEM_NAME}-${CMAKE_BUILD_TYPE}-${CMAKE_CXX_COMPILER_ID}")
endforeach()

# Specifying Libraries
find_package(Vulkan REQUIRED)
if(NOT Vulkan_FOUND)
  message("Error Finding Vulkan On Your Device")
endif()
# Some big setup for SDL
if(CMAKE_BUILD_TYPE STREQUAL "Debug" OR CMAKE_BUILD_TYPE STREQUAL "DebRelease")
  set(LIB_BUILD_TYPE "Debug")
else()
  set(LIB_BUILD_TYPE "Release")
endif()
find_library(SDL3_LIB
        NAMES SDL3
        PATHS "${CMAKE_SOURCE_DIR}/Libraries/Libs/${CMAKE_SYSTEM_NAME}-${LIB_BUILD_TYPE}-${CMAKE_CXX_COMPILER_ID}"
        NO_DEFAULT_PATH
)
if(NOT SDL3_LIB)
  message("ERROR: Required Library SDL3 Was Not Found! Did You Build 'Libraries' Before Building This Project?")
endif()

# Adding Sources
file(GLOB_RECURSE NO_SOURCES "${CMAKE_SOURCE_DIR}/Engine/Src/*.c" "${CMAKE_SOURCE_DIR}/Engine/Src/*.cpp")
file(GLOB_RECURSE STB_SOURCES "${CMAKE_SOURCE_DIR}/Headers/stb/*.cpp")

# Exporting NoEngine Library
add_library(${PROJECT_NAME} ${NO_SOURCES} ${STB_SOURCES})

# Adding Libraries
target_link_libraries(${PROJECT_NAME} PUBLIC
  ${SDL3_LIB}
  Vulkan::Vulkan
)

# Include Libraries
target_include_directories(${PROJECT_NAME} PUBLIC
  ${CMAKE_SOURCE_DIR}/Headers/glm
  ${CMAKE_SOURCE_DIR}/Headers/stb

  ${CMAKE_SOURCE_DIR}/Libraries/sdl3/include
  ${Vulkan_INCLUDE_DIRS}

  ${CMAKE_SOURCE_DIR}/Engine/Include
)

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
  target_compile_options(${PROJECT_NAME} PRIVATE
    $<$<CONFIG:Debug>: -g -O0 -Wall -Wextra -Wpedantic -Wno-unused-parameter>
    $<$<CONFIG:DebRelease>: -g -O2 -Wall -Wextra -Wpedantic -Wno-unused-parameter>
    $<$<CONFIG:Release>: -O3 -DNDEBUG -Wall -Wextra -Wpedantic -Wno-unused-parameter>
    $<$<CONFIG:RelExport>: -O2 -DNDEBUG -Wall -Wextra -Wpedantic -Wno-unused-parameter>
    $<$<CONFIG:Export>: -O3 -DNDEBUG -Wall -Wextra -Wpedantic -Wno-unused-parameter>
  )
elseif(MSVC)
  target_compile_options(${PROJECT_NAME} PRIVATE
    $<$<CONFIG:Debug>: /Zi /Od /W4 /RTC1>
    $<$<CONFIG:DebRelease>: /O2 /W4>
    $<$<CONFIG:Release>: /O2 /DNDEBUG /W4>
    $<$<CONFIG:RelExport>: /O2 /DNDEBUG /W4>
    $<$<CONFIG:Export>: /O2 /DNDEBUG /W4>
  )
  # Specially For Visual Studio
  set_target_properties(${PROJECT_NAME} PROPERTIES
  VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}"
  )
  set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
endif()

# Adding Compile Definitions
target_compile_definitions(${PROJECT_NAME} PUBLIC $<$<CONFIG:Debug>:NO_Debug>)
target_compile_definitions(${PROJECT_NAME} PUBLIC $<$<CONFIG:DebRelease>:NO_DebRelease>)
target_compile_definitions(${PROJECT_NAME} PUBLIC $<$<CONFIG:Release>:NO_Release>)
target_compile_definitions(${PROJECT_NAME} PUBLIC $<$<CONFIG:RelExport>:NO_RelExport>)
target_compile_definitions(${PROJECT_NAME} PUBLIC $<$<CONFIG:Export>:NO_Export>)
if(WIN32)
  add_compile_definitions(NO_PLATFORM_WINDOWS)
elseif(UNIX)
  add_compile_definitions(NO_PLATFORM_UNIX)
elseif(APPLE)
  add_compile_definitions(NO_PLATFORM_APPLE)
endif()

# Copying SDL shared libaries into the Bin folder
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory
  "${CMAKE_SOURCE_DIR}/Libraries/Bin/"
  "${CMAKE_SOURCE_DIR}/Bin/"
)

# Adding the editor CMake to build with this CMake
add_subdirectory(NoEditor)
