# OpenRGB Custom Rainbow Driver

A lightweight C++ driver for OpenRGB that creates a smooth, software-controlled rainbow effect. Designed for devices that lack built-in hardware rainbow modes on linux, such as the RGB keyboard of a laptop.

---

## Features

- **Low Resource Usage**  
  Although python would have been easier and better for my sanity, this uses efficient C++ and subsequently has far lower CPU usage.

- **Smart Scripts**  
  Automatically manages the local OpenRGB server (starts it if not already active).

- **Toggle Control**  
  Simple `rbow on` and `rbow off` commands.

- **Clean Exit**  
  Sets lights to static white when stopped, although this is quite simple to customize.

---

## Prerequisites

- Linux (in this case, I am using Lubuntu 24.04)
- OpenRGB (installed and configured)  
- libopenrgb (development library)  
- cmake and g++

---

## Installation

### 1. Clone the repository

    git clone https://github.com/varun0693/OpenRGB-rainbow-keyboard-implementation.git
    cd OpenRGB-rainbow-keyboard-implementation

### 2. Build the C++ driver

    mkdir build
    cd build
    cmake ..
    make

### 3. Set up the shortcut

1. Open the file ../shortcut-setup/bashrc_snippet.txt  
2. Copy its contents  
3. Paste it into your ~/.bashrc  
4. Important: Edit REPO_PATH to match where you cloned this repository  
5. Reload your shell configuration:

    source ~/.bashrc

---

## Usage

### Turn On

    rbow on

### Turn Off (sets lighting to white)

    rbow off

---
