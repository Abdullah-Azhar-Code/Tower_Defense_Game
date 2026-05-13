# 🏰 Tower Defense Game — OOP Semester Project

**Student:** Abdullah Azhar
**Roll Number:** 25L-2537
**Course:** Object Oriented Programming
**University:** National University of Computing & Emerging Sciences (FAST-NUCES)

---

## 📖 Project Overview

A fully playable **Tower Defense Game** built in C++ using SFML, developed as a semester project to demonstrate core Object-Oriented Programming concepts — Inheritance, Polymorphism, Encapsulation, and Runtime Polymorphism through a real, interactive graphical application.

Enemies march along a fixed winding path through a graveyard map. The player places defensive towers beside the path to destroy enemies before they escape. Each wave grows progressively harder. The player earns gold by defeating enemies and spends it to place new towers. The game ends when all lives are lost or all 5 waves are survived.

---

## 🎮 Gameplay

| Control | Action |
|---|---|
| **Mouse Click** (on map) | Place the currently selected tower |
| **Key 1** | Select Cannon Tower — $50 |
| **Key 2** | Select Sniper Tower — $75 |
| **Key 3** | Select Machine Gun Tower — $40 |
| **Key 4** | Select Slow Tower — $60 |
| **ESC** | Deselect tower |

- Start with **$500 gold** and **10 lives**
- Earn gold by defeating enemies
- Lose a life each time an enemy reaches the exit
- Waves start automatically after the previous one ends
- Survive all **5 waves** to win

---

## 🗂️ Project Structure

```
25L_2537_Abdullah_Azhar/
│
├── 25L_2537_Tower_Defence_Game.cpp   ← All implementations + main()
│
├── Entity.h           ← Abstract base class for all game entities
├── Enemy.h            ← Abstract enemy base (speed, HP, move, draw)
├── Basic_Enemy.h      ← Standard enemy — average speed & HP
├── Fast_Enemy.h       ← High speed, low HP
├── Tank_Enemy.h       ← Very slow, very high HP
├── Flying_Enemy.h     ← Ignores winding path; flies in a straight line
│
├── Tower.h            ← Abstract tower base (range, fire rate, damage)
├── Canon_Tower.h      ← High damage, slow fire rate
├── Sniper_Tower.h     ← Double damage, long range, single target
├── MachineGun_Tower.h ← Low damage, hits all enemies in range
├── Slow_Tower.h       ← Reduces enemy speed in range
│
├── Game.h             ← Core game loop, wave system, HUD, economy
│
├── enemy_pieces/      ← Enemy sprite images (.png)
├── tower_pieces/      ← Tower sprite images (.png)
├── other_game_assets/ ← Map and background images
├── Font/              ← Inter SemiBold font (.ttf)
└── Sound/             ← Background music (.ogg)
```

---

## 🏗️ Class Hierarchy (OOP Design)

```
Entity  (abstract)
├── Enemy  (abstract)
│   ├── BasicEnemy
│   ├── FastEnemy
│   ├── TankEnemy
│   └── FlyingEnemy
└── Tower  (abstract)
    ├── CannonTower
    ├── SniperTower
    ├── MachineGunTower
    └── SlowTower
```

All enemies and towers are stored and accessed through **base-class pointers**, demonstrating runtime polymorphism. Virtual functions `move()`, `draw()`, `attack()`, and `take_damage()` are overridden in every derived class.

---

## ⚔️ Enemy Types

| Enemy | Speed | HP | Special Trait |
|---|---|---|---|
| **BasicEnemy** | Normal | 100 | Default ground unit |
| **FastEnemy** | 2× | 50 | Difficult to hit before escaping |
| **TankEnemy** | 0.5× | 300 | Requires sustained damage to kill |
| **FlyingEnemy** | Normal | 80 | Flies straight across — ignores winding path |

---

## 🗼 Tower Types

| Tower | Damage | Behavior |
|---|---|---|
| **CannonTower** | 40 | Hits first enemy in range; slow fire rate |
| **SniperTower** | 80 | Double damage on single target; long range |
| **MachineGunTower** | 15 | Hits all enemies in range simultaneously |
| **SlowTower** | 0 | Reduces movement speed of all enemies in range |

---

## 🌊 Wave System

| Wave | Enemies | Max Count |
|---|---|---|
| Wave 1 | BasicEnemy only | 5 |
| Wave 2 | Basic + Fast | 8 |
| Wave 3 | Basic + Fast + Tank | 11 |
| Wave 4 | Basic + Fast + Tank + Flying | 14 |
| Wave 5 | All types — final wave | 17 |

Each wave spawns enemies with a 2-second delay between each one. Enemy count increases by 3 per wave.

---

## 🔧 OOP Concepts Demonstrated

| Concept | How It Is Used |
|---|---|
| **Inheritance** | Enemy and Tower hierarchies inherit from Entity |
| **Polymorphism** | `move()`, `draw()`, `attack()` called via base-class pointers |
| **Encapsulation** | Private/protected members with getters (`get_hp()`, `getRange()`, etc.) |
| **Abstract Classes** | Entity, Enemy, Tower all have pure virtual functions |
| **Constructors/Destructors** | Proper cleanup of dynamically allocated enemies and towers |
| **Operator Overloading** | Used for enemy comparison in targeting logic |

---

## 🖥️ GUI Library — SFML

This project uses **SFML (Simple and Fast Multimedia Library)** version 2.x.

### Installing SFML

**Windows (Visual Studio / MinGW):**
1. Download SFML 2.6 from [https://www.sfml-dev.org/download.php](https://www.sfml-dev.org/download.php)
2. Extract and link the `include/` and `lib/` folders in your IDE/build system
3. Copy the SFML `.dll` files to your project output directory

**Linux (Ubuntu/Debian):**
```bash
sudo apt-get install libsfml-dev
```

**macOS (Homebrew):**
```bash
brew install sfml
```

---

## 🚀 How to Compile and Run

### Using g++ (Linux / macOS)
```bash
g++ -std=c++17 "25L_2537_Tower_Defence_Game .cpp" \
    -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio \
    -o TowerDefense
./TowerDefense
```

### Using g++ (Windows with MinGW)
```bash
g++ -std=c++17 "25L_2537_Tower_Defence_Game .cpp" ^
    -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio ^
    -o TowerDefense.exe
TowerDefense.exe
```

### Using Visual Studio
1. Create a new **Empty C++ Project**
2. Add `25L_2537_Tower_Defence_Game.cpp` and all `.h` files
3. Configure SFML in **Project Properties → VC++ Directories** (include + library paths)
4. Add to **Linker → Input → Additional Dependencies:**
   `sfml-graphics.lib; sfml-window.lib; sfml-system.lib; sfml-audio.lib`
5. Build and run (F5)

> **Important:** Run the executable from inside the `25L_2537_Abdullah_Azhar/` folder so it can find the `enemy_pieces/`, `tower_pieces/`, `other_game_assets/`, `Font/`, and `Sound/` directories.

---

## ✨ Bonus Features Implemented

- 🎵 **Background Music** — Looping `.ogg` audio using SFML Audio module
- ❤️ **HP Bars** — Dynamic health bars above every enemy (green → yellow → red)
- 💰 **Live HUD** — Wave number, gold count, and lives permanently displayed
- 🖱️ **Mouse Tower Placement** — Click anywhere off the path to place a tower
- 🎯 **Game-Over & Win Screens** — Displayed when lives reach 0 or all waves clear

---

## ⚠️ Known Issues / Limitations

- The project does not include a tower upgrade system
- No save/load or high-score persistence
- Only one custom map is available (graveyard theme)
- Tower placement does not snap to a grid; placement is free-form
- The `.cpp` file must be compiled as a single translation unit (all implementations in one file)

---

## 📦 Submission

- **Zip Folder:** `25L-2537_Abdullah_Azhar.zip`
- **GitHub Repository:** *(add your repo link here)*
