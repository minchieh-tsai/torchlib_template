#!/bin/bash

# 設定腳本在遇到錯誤時終止
set -e

# 檢查是否提供了構建類型參數
BUILD_TYPE=$1
if [ -z "$BUILD_TYPE" ]; then
    echo "No build type specified. Using 'Release' by default."
    BUILD_TYPE=Release
fi

SOURCE_DIR=$(pwd)
BUILD_DIR="${SOURCE_DIR}/build"
INSTALL_DIR="${SOURCE_DIR}/install" 

if [ -d "$BUILD_DIR" ]; then
    echo "Removing existing build directory..."
    rm -rf $BUILD_DIR
fi
mkdir -p ${BUILD_DIR}

if [ -d "$INSTALL_DIR" ]; then
    echo "Removing existing install directory..."
    rm -rf $INSTALL_DIR
fi
mkdir -p ${INSTALL_DIR}


# 步骤1: 配置项目
echo "Configuring project..."
cmake -S ${SOURCE_DIR} -B ${BUILD_DIR} -DCMAKE_INSTALL_PREFIX=${INSTALL_DIR} -DCMAKE_BUILD_TYPE=${BUILD_TYPE}

# 步骤2: 构建项目
echo "Building project..."
cmake --build ${BUILD_DIR}

# 可选：运行测试
# echo "Running tests..."
# cmake --build ${BUILD_DIR} --target test

# 步骤3: 安装项目
echo "Installing project..."
cmake --install ${BUILD_DIR}
# cmake --install ${BUILD_DIR} --prefix ${INSTALL_DIR}

echo "Build and installation completed successfully."