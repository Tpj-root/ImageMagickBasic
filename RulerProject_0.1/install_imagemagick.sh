#!/usr/bin/env bash

set -e

echo "========================================"
echo " ImageMagick C++ Development Installer"
echo "========================================"

# Check for root privileges
if [[ $EUID -ne 0 ]]; then
    echo "Please run with sudo:"
    echo "sudo ./install_imagemagick.sh"
    exit 1
fi

echo
echo "[1/4] Updating package list..."
apt update

echo
echo "[2/4] Installing build tools..."
apt install -y \
    build-essential \
    cmake \
    pkg-config \
    g++ \
    make

echo
echo "[3/4] Installing ImageMagick development packages..."
apt install -y \
    imagemagick \
    libmagick++-dev

echo
echo "[4/4] Checking installation..."

echo
echo "ImageMagick version:"
magick --version || convert --version

echo
echo "pkg-config:"
pkg-config --modversion ImageMagick++

echo
echo "========================================"
echo "Installation Complete!"
echo "========================================"

echo
echo "Compiler flags:"
pkg-config --cflags ImageMagick++

echo
echo "Linker flags:"
pkg-config --libs ImageMagick++
