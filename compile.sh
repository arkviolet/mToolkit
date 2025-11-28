#!/usr/bin/env bash

set -ex

sourcePath=$(cd $(dirname $0) && pwd)

##################################################################################
PLATFORM_TYPE=x86_64

TOOLKIT_INSTALL_PREFIX_LINUX=$sourcePath/software/$PLATFORM_TYPE

### format ###
cd $sourcePath && mkdir -vp temp_3rd && cd temp_3rd

git clone https://github.com/fmtlib/fmt && cd fmt && git checkout origin/10.x

mkdir build_$PLATFORM_TYPE && cd build_$PLATFORM_TYPE

cmake .. \
  -DCMAKE_BUILD_TYPE=Release \
  -DCMAKE_VERBOSE_MAKEFILE=ON \
  -DCMAKE_C_FLAGS=-fPIC \
  -DCMAKE_CXX_FLAGS=-fPIC \
  -DFMT_TEST=OFF \
  -DCMAKE_INSTALL_PREFIX=$TOOLKIT_INSTALL_PREFIX_LINUX

make -j && make install

### toolkit ###
cd $sourcePath/toolkit && mkdir build_$PLATFORM_TYPE && cd build_$PLATFORM_TYPE

cmake .. \
  -DCMAKE_BUILD_TYPE=Release \
  -DCMAKE_VERBOSE_MAKEFILE=ON \
  -DCMAKE_C_FLAGS=-fPIC \
  -DCMAKE_CXX_FLAGS=-fPIC \
  -DFMT_TEST=OFF \
  -DCMAKE_INSTALL_PREFIX=$TOOLKIT_INSTALL_PREFIX_LINUX

make -j && make install

### toolkit enckit ###
cd $sourcePath/toolkit_enckit && mkdir build_$PLATFORM_TYPE && cd build_$PLATFORM_TYPE

cmake .. \
  -DCMAKE_BUILD_TYPE=Release \
  -DCMAKE_VERBOSE_MAKEFILE=ON \
  -DCMAKE_C_FLAGS=-fPIC \
  -DCMAKE_CXX_FLAGS=-fPIC \
  -DFMT_TEST=OFF \
  -DPLATFORM_TYPE=$PLATFORM_TYPE \
  -DCMAKE_INSTALL_PREFIX=$TOOLKIT_INSTALL_PREFIX_LINUX

make -j && make install

##################################################################################
