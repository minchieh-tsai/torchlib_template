cmake_minimum_required(VERSION 3.10)

project(modern-cmake-template VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 設置構建類型選項
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

# 調試信息和優化標誌
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

include(CTest)
include(cmake/pathSetting.cmake)


set(EXT_TORCH_DIR "${CMAKE_CURRENT_SOURCE_DIR}/external_libs/libtorch-cxx11-abi-shared-with-deps-2.2.2+cpu/libtorch")
find_package(Torch REQUIRED PATHS "${EXT_TORCH_DIR}" NO_DEFAULT_PATH)

file(GLOB EXT_TORCH_LIBRARIES "${EXT_TORCH_DIR}/lib/*.so*") 
install(FILES ${EXT_TORCH_LIBRARIES} DESTINATION lib)

set(EXT_OPENCV_DIR "${CMAKE_CURRENT_SOURCE_DIR}/external_libs/opencv-4.9.0/install")
find_package(OpenCV REQUIRED PATHS "${EXT_OPENCV_DIR}" NO_DEFAULT_PATH)

file(GLOB EXT_OPENCV_LIBRARIES "${EXT_OPENCV_DIR}/lib/*.so*") 
install(FILES ${EXT_OPENCV_LIBRARIES} DESTINATION lib)

add_subdirectory(libs)
add_subdirectory(app)
