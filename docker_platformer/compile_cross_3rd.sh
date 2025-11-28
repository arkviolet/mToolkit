#!/usr/bin/env bash
set -ex

sourcePath=/home/developer/workspace

PACKAGE_COMPILE_DIR=$sourcePath/packages
INSTALL_PREFIX_CROSS_LINUX=$sourcePath/software/cross
GIT_PATCH_DIR=$sourcePath/docker_platformer/patches

mkdir -vp $PACKAGE_COMPILE_DIR

# rk3568
PLATFORM=rk3568
TOOLCHAIN_FILE=$sourcePath/linux_crosss_env/rk3568.cmake

# linaro_arm
PLATFORM=linaro_arm
TOOLCHAIN_FILE=$sourcePath/linux_crosss_env/linaro_arm.cmake

###############################################################################
#ncurses
cd $PACKAGE_COMPILE_DIR

wget  https://ftp.gnu.org/pub/gnu/ncurses/ncurses-6.2.tar.gz

tar xvf ncurses-6.2.tar.gz && cd ncurses-6.2/

./configure $CONFIGURE_FLAGS \
    --with-shared \
    --prefix=$INSTALL_PREFIX_CROSS_LINUX/ncurses

make -j8 && make install

wget  https://ftp.gnu.org/pub/gnu/ncurses/ncurses-5.7.tar.gz

tar xvf ncurses-5.7.tar.gz && cd ncurses-5.7/

# linaro_arm
source $sourcePath/linux_crosss_env/environment-setup.linaro_arm.sh

./configure $CONFIGURE_FLAGS \
    --with-shared=no \
    --prefix=$INSTALL_PREFIX_CROSS_LINUX/linaro_arm/ncurses

make -j8 && make install

#cd $PACKAGE_COMPILE_DIR
#export NCURSES_CFLAGS="-I$INSTALL_PREFIX_CROSS_LINUX/linaro_arm/ncurses/include/ncurses -I$INSTALL_PREFIX_CROSS_LINUX/linaro_arm/ncurses/include/"
#export NCURSES_LIBS="-L$INSTALL_PREFIX_CROSS_LINUX/linaro_arm/ncurses/lib -lncurses"
###############################################################################
# minicom
cd $PACKAGE_COMPILE_DIR

wget https://fossies.org/linux/misc/minicom-2.9.tar.bz2

tar -xjvf  minicom-2.9.tar.bz2 && cd minicom-2.9/

# rk3568
source $sourcePath/linux_crosss_env/environment-setup.buildroot.sh

./configure $CONFIGURE_FLAGS --prefix=$INSTALL_PREFIX_CROSS_LINUX/rk3568/minicom

make -j8 && make install

make clean


###############################################################################
# boost
cd $PACKAGE_COMPILE_DIR

git clone https://github.com/boostorg/boost.git

cd boost && git checkout boost-1.79.0 && git submodule update --init --recursive

# rk3568
./bootstrap.sh --prefix=$INSTALL_PREFIX_CROSS_LINUX/rk3568/boost

sed -i '/using gcc ;/ c\    using gcc : : /opt/sdk/rk3568/aarch64-linux-gcc-v12.3/bin/aarch64-buildroot-linux-gnu-gcc ;' project-config.jam

./b2 -j8

./b2 install

./b2 --clean

###############################################################################
# can-utils
cd $PACKAGE_COMPILE_DIR

git clone https://github.com/linux-can/can-utils.git

cd can-utils && git checkout v2023.03

# rk3568
mkdir  rk3568 && cd rk3568

cmake ..    -DCMAKE_INSTALL_PREFIX=$INSTALL_PREFIX_CROSS_LINUX/$PLATFORM/can-utils \
            -DCMAKE_TOOLCHAIN_FILE=$TOOLCHAIN_FILE

make -j8 && make install && make clean
