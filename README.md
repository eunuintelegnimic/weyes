**`README.md`**
# weyes

**weyes** is a C project like xorg-xeyes using the [raylib](https://www.raylib.com/) library.

## Features

- Built in C
- Uses the raylib for graphics
- Simple CMake-based build system

## Requirements

- CMake ≥ 3.16
- A C compiler
- raylib (>= 5.0)

### Installing raylib

#### On Arch btw:
```bash
sudo pacman -Sy raylib
```

#### On Ubuntu/Debian:
```bash
sudo apt install libraylib-dev
```

#### On macOS (with Homebrew):

```bash
brew install raylib
```

## Build Instructions

```bash
git clone https://github.com/eunuintelegnimic/weyes.git
cd weyes
mkdir build
cd build
cmake ..
make
```

## Installation

```bash
sudo make install
```

> You can also set a custom installation prefix:

```bash
cmake -DCMAKE_INSTALL_PREFIX=/your/custom/path 
```

## License

This project is licensed under the [MIT License](./LICENSE).

---

© 2025 eunuintelegnimic

