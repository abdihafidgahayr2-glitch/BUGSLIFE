A Bug's Life — C++ OOP Simulation

A console-based simulation of insects moving around a grid, built in C++ to practice object-oriented design — inheritance, polymorphism, and abstract classes.

👤 Author

Abdihafid Gahayr — LinkedIn | GitHub

📋 Project Overview

The simulation loads a set of bugs onto a 10x10 board from a text file, then lets each bug move around the board according to its own movement behaviour. Every bug tracks its position, direction, health, and a full history of the cells it has visited, which can be displayed or exported once the simulation ends.

✨ Features
Board initialization — loads bug starting positions and types from bugs.txt
Three bug types with unique movement — Crawler, Hopper, and Jumper, each implementing its own move() behaviour
Step-by-step or automatic simulation — "tap" the board one step at a time, or run the simulation automatically once per second
Bug lookup — find and inspect any bug by ID (position, direction, health, status)
Life history tracking — every bug records the full path of cells it has moved through
Board and cell display — view the state of every bug or every cell on the board
Export results — write each bug's life history to bugs_life_history.out on exit
🏗️ Design & Tech Stack
Language: C++
Build system: CMake
OOP concepts applied:
Bug is an abstract base class (pure virtual move() and getType()) defining shared state — ID, position, direction, health, alive status, and movement path
Crawler, Hopper, and Jumper inherit from Bug and override move() with their own movement rules — a classic example of polymorphism
Board manages the full set of bugs and coordinates the simulation
📁 Project Structure
BUGSLIFE/
├── Bug.h / Bug.cpp            # Abstract base class
├── Crawler.h / Crawler.cpp    # Bug subclass
├── Hopper.h / Hopper.cpp      # Bug subclass
├── Jumper.h / Jumper.cpp      # Bug subclass
├── Board.h / Board.cpp        # Manages bugs and runs the simulation
├── main.cpp                   # Menu-driven entry point
└── CMakeLists.txt
🚀 Getting Started
Prerequisites
A C++ compiler (e.g. g++ or MSVC)
CMake
Build and run
bash
mkdir build && cd build
cmake ..
cmake --build .
./BUGSLIFE

You'll need a bugs.txt file in the working directory describing the starting bugs before choosing option 1 from the menu.

🎮 Menu Options
Option	Description
1	Initialize the bug board from bugs.txt
2	Display all bugs
3	Find a bug by ID
4	Tap the board (advance the simulation by one step)
5	Display each bug's life history
6	Display all cells on the board
7	Run the simulation automatically (one tap per second)
8	Exit and write life histories to bugs_life_history.out
