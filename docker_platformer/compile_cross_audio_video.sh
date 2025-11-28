#!/usr/bin/env bash

set -ex

sourcePath=/home/developer/workspace

PACKAGE_COMPILE_DIR=$sourcePath/packages
INSTALL_PREFIX_CROSS_LINUX=$sourcePath/software/cross

cd $sourcePath

mkdir -vp $PACKAGE_COMPILE_DIR
mkdir -vp $INSTALL_PREFIX_CROSS_LINUX

##########################################################################################
# rk3568
cd $PACKAGE_COMPILE_DIR

git clone -b 1.20 
--depth=1 https://gitlab.freedesktop.org/gstreamer/gstreamer.git

cd gstreamer && cp $sourcePath/docker_platformer/patches/gst_buildroot.txt .

meson 
--cross-file gst_buildroot.txt build_rk3568 \
    -Dgtk_doc=disabled \
    -Dtests=disabled \
    -Dexamples=disabled \
    -Dgst-plugins-base:typefind=enabled \
    -Dgst-plugins-base:app=enabled \
    -Dgst-plugins-base:playback=enabled \
    -Dgst-plugins-base:videotestsrc=enabled \
    -Dgst-plugins-base:videoconvert=enabled \
    -Dgst-plugins-good:autodetect=enabled \
    -Dgst-plugins-good:v4l2=enabled \
    -Dgpl=enabled \
    -Dgst-plugins-ugly:x264=enabled \
    -Dgstreamer:tools=enabled \
    --reconfigure \
    --prefix=$INSTALL_PREFIX_CROSS_LINUX/rk3568/gstreamer

ninja -C build_rk3568

meson install -C build_rk3568/

ninja -C build_rk3568 clean

##########################################################################################
cd $PACKAGE_COMPILE_DIR

wget https://ffmpeg.org/releases/ffmpeg-4.4.4.tar.xz

mkdir ffmpeg-4.4.4 && tar -xf ffmpeg-4.4.4.tar.xz --strip-components=1 -C ffmpeg-4.4.4

cd ffmpeg-4.4.4

# TODO should git patch

./configure \
    --enable-cross-compile \
    --cross-prefix=/opt/aarch64-buildroot-linux-gnu_sdk-buildroot/bin/aarch64-buildroot-linux-gnu- \
    --sysroot=/opt/aarch64-buildroot-linux-gnu_sdk-buildroot/aarch64-buildroot-linux-gnu/sysroot \
    --pkg-config="/opt/aarch64-buildroot-linux-gnu_sdk-buildroot/bin/pkg-config" \
    --pkg-config="/opt/aarch64-buildroot-linux-gnu_sdk-buildroot/bin/pkg-config" \
    --prefix=$INSTALL_PREFIX_CROSS_LINUX/rk3568/ffmpeg \
    --arch="aarch64" \
    --target-os="linux" \
    --disable-stripping \
    --enable-static \
    --enable-shared \
    --enable-avfilter \
    --disable-version3 \
    --enable-logging \
    --enable-optimizations \
    --disable-extra-warnings \
    --enable-avdevice \
    --enable-avcodec \
    --enable-avformat \
    --enable-network \
    --disable-gray \
    --enable-swscale-alpha \
    --disable-small \
    --enable-dct \
    --enable-fft \
    --enable-mdct \
    --enable-rdft \
    --disable-crystalhd \
    --disable-dxva2 \
    --enable-runtime-cpudetect \
    --disable-hardcoded-tables \
    --disable-mipsdsp \
    --disable-mipsdspr2 \
    --disable-msa \
    --enable-hwaccels \
    --disable-cuda \
    --disable-cuvid \
    --disable-nvenc \
    --disable-avisynth \
    --disable-frei0r \
    --disable-libopencore-amrnb \
    --disable-libopencore-amrwb \
    --disable-libdc1394 \
    --disable-libgsm \
    --disable-libilbc \
    --disable-libvo-amrwbenc \
    --disable-symver \
    --disable-doc \
    --disable-gpl \
    --disable-nonfree \
    --enable-ffmpeg \
    --enable-ffplay \
    --disable-libjack \
    --enable-libv4l2 \
    --disable-avresample \
    --enable-ffprobe \
    --disable-libxcb \
    --disable-postproc \
    --enable-swscale \
    --enable-indevs \
    --disable-alsa \
    --enable-outdevs \
    --enable-pthreads \
    --enable-zlib \
    --enable-bzlib \
    --disable-libfdk-aac \
    --disable-libcdio \
    --disable-gnutls \
    --enable-openssl \
    --disable-libdrm \
    --enable-libopenh264 \
    --disable-vaapi \
    --disable-vdpau \
    --disable-mmal \
    --disable-omx \
    --disable-omx-rpi \
    --disable-libopencv \
    --disable-libopus \
    --disable-libvpx \
    --disable-libass \
    --disable-libbluray \
    --disable-libmfx \
    --enable-librtmp \
    --disable-libmp3lame \
    --disable-libmodplug \
    --disable-libspeex \
    --disable-libtheora \
    --disable-iconv \
    --disable-libfreetype \
    --disable-fontconfig \
    --enable-libopenjpeg \
    --disable-libx264 \
    --disable-libx265 \
    --disable-libdav1d \
    --disable-x86asm \
    --disable-mmx \
    --disable-sse \
    --disable-sse2 \
    --disable-sse3 \
    --disable-ssse3 \
    --disable-sse4 \
    --disable-sse42 \
    --disable-avx \
    --disable-avx2 \
    --disable-armv6 \
    --disable-armv6t2 \
    --enable-vfp \
    --enable-neon \
    --disable-altivec \
    --extra-libs=-latomic \
    --enable-pic \
    --cpu="cortex-a55"

make -j8 && make install && make clean

##########################################################################################