
cmake_minimum_required(VERSION 3.31)
project(SodaCan)

# Settings and Variables
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Settings up the build type
set(CMAKE_CONFIGURATION_TYPES "Debug;DebRelease;Release;RelExport;Export" CACHE STRING "Choose A Build Type (Debug | Release)" FORCE)
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release")
  message("No Build Type Was Selected. So Defaulting To Release")
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

# Exporting The Application
file(GLOB_RECURSE SODACAN_SOURCES "./Src/*.cpp" "./Src/*.c")
add_executable(${PROJECT_NAME} ${SODACAN_SOURCES})

# Adding libraries
find_library(IMGUI_LIB
    NAMES imgui
    PATHS "${CMAKE_SOURCE_DIR}/Libraries/Libs/${CMAKE_SYSTEM_NAME}-${LIB_BUILD_TYPE}-${CMAKE_CXX_COMPILER_ID}"
    NO_DEFAULT_PATH
)
if(NOT IMGUI_LIB)
  message("ERROR: Required Library imgui Was Not Found! Did You Build 'Libraries' Before Building This Project?")
endif()
target_link_libraries(${PROJECT_NAME} PUBLIC
    SodaEngine
    ${IMGUI_LIB}
)

# adding include folders
target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_SOURCE_DIR}/SodaEngine/Include
    ${CMAKE_SOURCE_DIR}/Libraries/imgui

    ${PROJECT_SOURCE_DIR}/Include
)

# Post Build
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${CMAKE_SOURCE_DIR}/Assets"
    "${CMAKE_RUNTIME_OUTPUT_DIRECTORY_${CONFIG_UPPER}}/Assets"
)
