# CPPND: Capstone Snake Game

This program is an evolution of the Snake game starter. Instead of simply chasing after one fruit, the game now has four different kinds of fruit, each one with different effects and presentation.

- Strawboring: Adds points and increases the snake's length
- Raspboost: Increases the snake's speed
- Aprinot: Adds points without increasing length
- Clementime: Adds a large number of points, but slowly decays to nothing

In addition, the game now randomly generates wall blocks which slowly decay over time. When a wall decays totally, a new wall is created in a new location. If the snake hits a wall block, the game ends.

When you run the program, the game plays. Try not to die.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`

## Rubric

- [x] A README is included
- [x] The README includes information about the project
- [x] The README indicates which points on the rubric have been met
- [x] The submission compiles and runs without errors

---

- [x] The submission uses a variety of control structures (functions, loops, ifs, and a switch statement are all found in `game.cpp`)
- [x] The project code is organized into classes with class attributes to hold the data, and class methods to perform tasks. (The `fruit.h` file contains several classes, and there is one in `wall.h`)
- [x] Classes encapsulate behavior. (`fruit.h`)
- [x] Classes follow an appropriate inheritance hierarchy. (`fruit.h` contains a base class and several child classes)
- [x] Overloaded constructors in `fruit.h` for the base `Fruit` class
- [x] Class constructors utilize member initialization lists. (`fruit.h`, `wall.h`)
- [x] Classes use appropriate access specifiers for class members. (`fruit.h`, `wall.h`)
- [x] The project uses Object Oriented Programming techniques. (`fruit.h`, `wall.h`)