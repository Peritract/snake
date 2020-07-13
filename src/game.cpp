#include "game.h"
#include <iostream>
#include "SDL.h"

Game::Game(std::size_t grid_width, std::size_t grid_height)
    : snake(grid_width, grid_height),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width)),
      random_h(0, static_cast<int>(grid_height)) {
  PlaceFruit();
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, snake);
    Update();
    renderer.Render(snake, fruit, walls);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // Every second, update the walls
    if (frame_end - title_timestamp >= 1000) {

      // Update the walls
      UpdateWalls();

      // And the window title
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

// Update walls
void Game::UpdateWalls() {
  // Decay each wall
  for (auto wall : walls) {
    wall.update();
  }

  // Remove any walls with 0 duration left
  std::remove_if(walls.begin(), walls.end(), [](Wall w){ return w.getDuration(); });

  // If fewer than five walls remain, add a new one
  if (walls.size() < 5) {
    PlaceWall();
  }
}

// Place a new wall
void Game::PlaceWall() {
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by the snake or fruit before placing
    if (!snake.SnakeCell(x, y) && !(x == fruit.getX() && y == fruit.getY())) {

      // Random duration (5-30 seconds)
      int duration = rand() % 30 + 5;
      walls.emplace_back(Wall(x, y, duration));
      std::cout << "New wall" << std::endl;
      break;
    }
  }
}

// Place a new random fruit
void Game::PlaceFruit() {
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item before placing
    // fruit.
    if (!snake.SnakeCell(x, y)) {
      break;
    }
  }

  // Select and create a fruit
  switch(rand()%(3)){
    case 0:
      fruit = Strawboring(x, y);
      break;
    case 1:
      fruit = Raspboost(x, y);
      break;
    case 2:
      fruit = Aprinot(x, y);
      break;
  }
  std::cout << "New Fruit (" << x << ", " << y << ")" << std::endl;
}

void Game::Update() {
  if (!snake.alive) return;

  snake.Update();

  int new_x = static_cast<int>(snake.head_x);
  int new_y = static_cast<int>(snake.head_y);

  // Check if there's fruit over here
  if (fruit.getX() == new_x && fruit.getY() == new_y) {
    score += fruit.getVal();
    PlaceFruit();

    // Grow snake
    if (fruit.getLengthens()){
      snake.GrowBody();
    }

    // Increase speed
    if (fruit.getSpeeds()){
      snake.speed += 0.02;
    }
  }

  // Check if the snake has hit a wall
  for (auto wall : walls) {
    if (wall.getX() == new_x && wall.getY() == new_y) {
      snake.alive = false;
      return;
    }
  }
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }