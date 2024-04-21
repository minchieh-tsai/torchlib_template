cmake_minimum_required(VERSION 3.10)

project(modern-cmake-template VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(CTest)
include(cmake/pathSetting.cmake)

# find_package(Torch REQUIRED
#             NO_MODULE
#             PATHS ${CMAKE_CURRENT_SOURCE_DIR}/external_libs/libtorch-cxx11-abi-shared-with-deps-2.2.2+cpu/libtorch
#             NO_DEFAULT_PATH)

set(EXT_TORCH_DIR "${CMAKE_CURRENT_SOURCE_DIR}/external_libs/libtorch-cxx11-abi-shared-with-deps-2.2.2+cpu/libtorch")
find_package(Torch REQUIRED PATHS "${EXT_TORCH_DIR}" NO_DEFAULT_PATH)

# 安装 Torch 的动态库到您的项目库目录中
file(GLOB EXT_TORCH_LIBRARIES "${EXT_TORCH_DIR}/lib/*.so*") 
install(FILES ${EXT_TORCH_LIBRARIES} DESTINATION lib)


add_subdirectory(libs)
add_subdirectory(app)
