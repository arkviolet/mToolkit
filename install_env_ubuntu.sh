#!/bin/bash

sudo apt-get update

sudo apt-get upgrade

# linux tool
sudo apt-get install ack vim tree wget xvfb adb rar git gitk gitg curl -y

sudo apt-get install minicom yakuake guake htop atop iotop lsof dstat sysstat -y

sudo apt-get install terminator cutecom imagemagick apt-file openssh-server -y

sudo apt-get install software-properties-common -y

# dev
sudo apt-get install gcc g++ cmake make automake autoconf -y

sudo apt-get install libmemcached-dev libtokyocabinet-dev -y

sudo apt-get install libsdbus-c++ libsdbus-c++-dev libdbus-1-dev -y

sudo apt-get install libboost-all-dev libsqlite3-dev libopencv-dev -y

sudo apt-get install libgflags-dev libgoogle-glog-dev libprocess-cpp-dev -y

sudo apt-get install libmysqlcppconn-dev libyaml-cpp-dev libusb-1.0-0-dev -y

sudo apt-get install libatlas-base-dev libsuitesparse-dev libgtk-3-dev -y

sudo apt-get install libbz2-dev libegl1-mesa-dev libwayland-dev libxkbcommon-dev wayland-protocols -y

sudo apt-get install libvpx-dev libopus-dev libfdk-aac-dev libmp3lame-dev libx265-dev libnuma-dev -y

sudo apt-get install libglew-dev intel-mkl-full libsuitesparse-dev libpcl-dev -y

sudo apt-get install libssl-dev libudev-dev libevdev-dev libcurl4-gnutls-dev -y

sudo apt-get install libdwarf-dev libperl libperl-dev libdwarf-freebsd-dev -y

sudo apt-get install systemtap-sdt-dev libaudit-dev libdw-dev libslang2-dev libgtk2.0-dev libunwind-dev -y

sudo apt-get install binutils-dev libiberty-dev libelf-dev libfuse-dev -y

sudo apt-get install python2-dev python3-dev pulseaudio libpulse-dev libsndfile-dev libsndfile1 -y

sudo apt-get install protobuf-compiler-grpc libgrpc++-dev libsystemd-dev libgstreamer1.0-dev -y

# app
sudo apt-get install redis-tools redis-server -y

sudo apt-get install docker.io docker-compose -y

sudo apt-get install gfortran mysql-server mysql-client -y

sudo apt-get install ffmpeg yasm fuse gstreamer1.0-rtsp python3 python3-pip -y

# kernel
sudo apt-get install linux-tools-common linux-tools-generic linux-tools-$(uname -r)

# gcc g++
sudo add-apt-repository ppa:ubuntu-toolchain-r/test && sudo apt-get update
sudo apt-get install gcc-13 g++-13 -y 
sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-13 100
sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-13 100

# ecal
sudo add-apt-repository ppa:ecal/ecal-latest && sudo apt-get update
sudo apt-get install ecal -y

#####################################################################################################

# mqtt                  https://github.com/emqx/MQTTX/releases/tag/v1.10.0
# BloomRPC              https://github.com/bloomrpc/bloomrpc/releases
# grpcurl               https://github.com/fullstorydev/grpcurl/releases
# mqtt ca_certificates  https://github.com/owntracks/tools/blob/master/TLS/generate-CA.sh
# vpn software          https://github.com/2dust/v2rayN/releases/download/6.21/v2rayN-With-Core.zip

# perf
mkdir -vp ~/workspace && cd ~/workspace
wget http://ftp.sjtu.edu.cn/sites/ftp.kernel.org/pub/linux/kernel/v4.x/linux-4.9.xxx.tar.gz  #需要与当前内核版本相对对应
tar -zxvf linux-4.9.xxx.tar.gz
cd linux-4.9.xxx/tools/perf/
make -j4

#
# python3 pip3
#
  if [ ! -d ~/.pip/ ]; then
    mkdir -p ~/.pip/
    chmod 755 -R ~/.pip/
  fi

  sh -c 'echo "[global]\nindex-url = https://pypi.tuna.tsinghua.edu.cn/simple" >~/.pip/pip.conf'
    pip3 install --upgrade pip
    pip3 install bs4
    pip3 install ssh
    pip3 install lulu
    pip3 install xlrd
    pip3 install lxml
    pip3 install pyqt5
    pip3 install psutil
    pip3 install pandas
    pip3 install pillow
    pip3 install you-get
    pip3 install pyquery
    pip3 install pymysql
    pip3 install openpyxl
    pip3 install html5lib
    pip3 install paramiko
    pip3 install pycrypto
    pip3 install selenium
    pip3 install requests
    pip3 install FlashText
    pip3 install matplotlib
    pip3 install simplejson
    pip3 install xlsxwriter
    pip3 install sqlalchemy
    pip3 install goto-statement
    pip3 install mysql-connector
    pip3 install pyvirtualdisplay
    sudo -H pip3 install -U jetson-stats -i https://pypi.tuna.tsinghua.edu.cn/simple

#
# download android NDK21
#
cd ~/package/ && wget https://dl.google.com/android/repository/android-ndk-r21e-linux-x86_64.zip

unzip android-ndk-r21e-linux-x86_64.zip

rm android-ndk-r21e-linux-x86_64.zip

mv android-ndk-r21e ~/software/
