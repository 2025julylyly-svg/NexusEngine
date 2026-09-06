# NexusEngine

**NexusEngine** is a lightweight 2D game engine written in modern C++ (C++23/C++26), built on top of **SFML**.

> ⚠️ **Important**: This project **only runs on Linux**.

---

## Overview

NexusEngine provides a simple framework for creating 2D games with:

- Window management
- Custom shape actors (Circle, Rectangle, Polygon)
- Spatial Hashing based collision detection (Broad-phase + Narrow-phase)
- Low-level keyboard & mouse input system (using Linux `/dev/input`)
- Custom data structures (Vector, HashMap, Set, String, Queue, etc.)
- Game loop with fixed FPS
- User-defined game logic via inheritance

The engine is still under active development.

---

## Features

### Core Systems
| System | Description |
|--------|-------------|
| **Window System** | Custom `WS` class inheriting from `sf::RenderWindow` with background color control |
| **Input System** | Direct reading from Linux input devices (`/dev/input/...`) for keyboard and mouse |
| **Collision System** | Spatial Hashing Grid (Broad-phase) + SAT / geometric tests (Narrow-phase) |
| **Shape Actors** | `Circle`, `Rectangle`, `Polygon` with movement helpers and bounds |
| **Game Logic** | Abstract `GameLogic` class for user game code |

### Collision Detection
- **Broad-phase**: Spatial Hashing Grid (`CreateGridWindow`)
- **Narrow-phase**:
  - Circle vs Circle
  - Circle vs Rectangle
  - Circle vs Polygon
  - Rectangle vs Rectangle
  - Rectangle vs Polygon
  - Polygon vs Polygon
- Uses Separating Axis Theorem (SAT) for polygon collisions

### Custom Libraries
The project includes its own implementations of common data structures:
- `Vector`
- `HashMap` / `Map`
- `HashSet` / `Set`
- `String`
- `Queue`
- `VecPos` (2D position vector)
- `VecCol` (Color helper)

---

## Project Structure

```
NexusEngine/
├── Engine/
│   ├── Actors/Shapes/          # Circle, Rectangle, Polygon
│   ├── MainEngine/             # Engine class (core loop)
│   ├── Systems/
│   │   ├── Collision/          # Spatial Hashing + Narrow-phase
│   │   ├── Input/              # Keyboard & Mouse input
│   │   └── Window/             # Window system
│   └── UserGameLogic/          # Abstract GameLogic base class
├── EngineLibrary/
│   ├── VectorColor/            # VecCol
│   └── VectorPosition/         # VecPos
├── Library/                    # Custom data structures
│   ├── HashSet/
│   ├── MappingData/
│   ├── MapWithoutHashData/
│   ├── QUEUE/
│   ├── STRING/
│   ├── Set/
│   └── VectorDataStruct/
├── main.cpp
└── CMakeLists.txt
```

---

## Requirements

- **OS**: Linux only
- **Compiler**: Supporting C++23 / C++26
- **CMake**: ≥ 3.xx (project currently sets `cmake_minimum_required(VERSION 4.3)`)
- **SFML**: 2.x or 3.x (`sfml-graphics`, `sfml-window`, `sfml-system`)
- Access to `/dev/input` devices (keyboard & mouse)

> **Note**: The input system currently hardcodes specific device paths (e.g. `usb-SEMICO_USB_Keyboard-event-kbd`). You may need to adjust these paths for your hardware.

---

## Building

```bash
mkdir build && cd build
cmake ..
make
```

Or with Ninja:

```bash
cmake -G Ninja ..
ninja
```

---

## Basic Usage

```cpp
#include "Engine/MainEngine/Engine.h"
#include "Engine/UserGameLogic/GameLogic.h"

// Create your game logic
class MyGame : public GameLogic {
public:
    void Main() const override {
        // Your game update code here
        // Access: Input, Window, CollisionChecker
    }
};

int main() {
    MyGame logic;
    Engine engine;

    engine.CreateWindow({900, 900}, 60);  // size, fps
    engine.Run(&logic);

    return 0;
}
```

### Creating Shapes

```cpp
Circle* circle = new Circle(100.f, 100.f, 30.f);
circle->SetSpeed(5.f);
engine.CreateShape(circle);
```

---

## Current Limitations

- Linux-only (input system uses `/dev/input`)
- Input device paths are hardcoded
- Still in early development stage
- Limited documentation / examples
- Some systems are incomplete or under refactoring

---

## License

No license has been specified yet.

---

## Author

[Peyman-Dev-Eng]([https://github.com/Peyman-Dev-Eng])

---

**Status**: Finished
