# First Mini Game — SFML & C++

> A small 2D mini game built while learning the **SFML** (Simple and Fast Multimedia Library) framework with **C++**.

---

## Overview

This is a personal learning project created to explore game development fundamentals using **SFML** alongside **C++**. It covers the basics of rendering, input handling, and the game loop pattern.

**Languages & Tools:** C++, C, SFML, Makefile, CMake

---

## Project Structure

```
First-Mini-Game/
└── SFMLandC++/     # Main source code and build files
```

---

## Features

- 2D rendering with SFML
- Keyboard/mouse input handling
- Basic game loop (update → render)
- Window management and event handling
- Simple game entities and movement

---

## Requirements

- [SFML 2.x](https://www.sfml-dev.org/download.php) installed on your system
- A C++ compiler (g++ / clang++)
- `make` or `cmake`

### Installing SFML

**Ubuntu/Debian:**
```bash
sudo apt-get install libsfml-dev
```

**macOS (Homebrew):**
```bash
brew install sfml
```

**Windows:**
Download the appropriate package from [sfml-dev.org](https://www.sfml-dev.org/download.php) and link it to your project.

---

## Build & Run

### Using Makefile
```bash
cd SFMLandC++
make
./game
```

### Using CMake
```bash
cd SFMLandC++
mkdir build && cd build
cmake ..
make
./game
```

---

## What I Learned

- Setting up an SFML project from scratch with Makefile and CMake
- Creating and managing an SFML `RenderWindow`
- Handling real-time keyboard and mouse events
- Drawing shapes, sprites, and text on screen
- Implementing a basic game loop with delta time

---

## Author

**Manos Dimitris**
- Heraklion, Crete, Greece
- [LinkedIn](https://www.linkedin.com/in/manos-dimitris-442330273/)
- [GitHub](https://github.com/ManosDimitris)

This project was built for personal learning purpos
