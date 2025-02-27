#!/bin/bash
set -e

apt-get update
apt-get install -y gcc wget tar build-essential bison flex libgmp3-dev libmpc-dev libmpfr-dev texinfo
apt-get install -y nasm qemu-system-x86 git
rm -rf /var/lib/apt/lists/*

export PREFIX="$HOME/opt/cross"
export TARGET=i686-elf
export PATH="$PREFIX/bin:$PATH"

mkdir ~/src

cd ~/src
wget https://ftp.gnu.org/gnu/binutils/binutils-2.43.1.tar.xz
tar -xf binutils-2.43.1.tar.xz
mkdir build-binutils
cd build-binutils
../binutils-2.43.1/configure --target=$TARGET --prefix=$PREFIX --with-sysroot --disable-nls --disable-werror
make -j$(nproc)
make -j$(nproc) install

cd ~/src
wget https://ftp.gnu.org/gnu/gcc/gcc-14.2.0/gcc-14.2.0.tar.xz
tar -xf gcc-14.2.0.tar.xz
mkdir build-gcc
cd build-gcc
../gcc-14.2.0/configure --target=$TARGET --prefix=$PREFIX --disable-nls --enable-languages=c,c++ --without-headers --disable-hosted-libstdcxx
make -j$(nproc) all-gcc
make -j$(nproc) all-target-libgcc
make -j$(nproc) install-gcc
make -j$(nproc) install-target-libgcc

echo "export PATH=\"\$HOME/opt/cross/bin:\$PATH\"" >> ~/.profile

mkdir /root/os
cd /root/os
git clone https://github.com/ohadk123/projectK .