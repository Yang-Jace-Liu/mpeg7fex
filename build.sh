#!/bin/sh

# Clone the opencv library because we need it
git clone https://github.com/opencv/opencv -b 3.1.0 --depth 1

# Folders we need
mkdir -p dependencies
mkdir -p opencv/build

# Build OpenCV
cd opencv/build
cmake -D CMAKE_BUILD_TYPE=Release -D CMAKE_INSTALL_PREFIX=../../dependencies/ -DOPENCV_GENERATE_PKGCONFIG=ON -DENABLE_PRECOMPILED_HEADERS=OFF -DWITH_CUDA=OFF -DBUILD_opencv_gpu=OFF ..
make -j$(nproc)
make install
cd ../..

# Build MPEG7Fex
mkdir build && cd build
cmake -D CMAKE_BUILD_TYPE=Release ..
make -j$(nproc)
