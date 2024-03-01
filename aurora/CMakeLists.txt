# CMAKE_SYSTEM_PROCESSOR - CPU architecture name (armv7l, aarch64, x86_64)
# CMAKE_BUILD_TYPE       - Build mode (debug, profile, release)
# PSDK_VERSION           - Build psdk exact version
# PSDK_MAJOR             - Build psdk major version

cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME url_launcher_aurora)
set(PLUGIN_NAME  url_launcher_aurora_platform_plugin)

project(${PROJECT_NAME} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wno-psabi")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

find_package(PkgConfig REQUIRED)
find_package(Qt5 REQUIRED COMPONENTS Core)
find_package(Qt5 REQUIRED COMPONENTS Qml)

pkg_check_modules(FlutterEmbedder REQUIRED IMPORTED_TARGET flutter-embedder)
pkg_check_modules(RuntimeManager REQUIRED IMPORTED_TARGET runtime-manager-qt5)

add_library(${PLUGIN_NAME} SHARED 
    url_launcher_aurora_plugin.cpp
    invoke_manager/invoke_manager.cpp
    intent/intent_default.cpp
    utils/utils.cpp
)

set_target_properties(${PLUGIN_NAME} PROPERTIES CXX_VISIBILITY_PRESET hidden AUTOMOC ON)
set_target_properties(${PLUGIN_NAME} PROPERTIES CXX_VISIBILITY_PRESET hidden)

target_link_libraries(${PLUGIN_NAME} PRIVATE PkgConfig::FlutterEmbedder PkgConfig::RuntimeManager)
target_link_libraries(${PLUGIN_NAME} PUBLIC Qt5::Core)
target_link_libraries(${PLUGIN_NAME} PUBLIC Qt5::Qml)

target_include_directories(${PLUGIN_NAME} PRIVATE ${FLUTTER_DIR})
target_include_directories(${PLUGIN_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(${PLUGIN_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME})

target_compile_definitions(${PLUGIN_NAME} PRIVATE PLUGIN_IMPL)
