#include <iostream>  // for std::endl
#include <ostream>

#include "third_party/absl/time/clock.h"
#include "third_party/absl/time/time.h"

bool gameOver = false;
const int SCREEN_HEIGHT = 25;
const int SCREEN_WIDTH = 80;

int snakeHeadXPos = SCREEN_HEIGHT / 2;
int snakeHeadYPos = SCREEN_WIDTH / 2;

namespace snake {

void StartGame() { RunGameLoop(); }

void RunGameLoop() { DrawMap(); }

void DrawMap() {
  while (!gameOver) {
    system("clear");
    // Loop over the map area (the terminal in this case)
    for (int i = 0; i < SCREEN_HEIGHT; i++) {
      for (int j = 0; j < SCREEN_WIDTH; j++) {
        // Draw background borders
        if (i == 0 || j == SCREEN_WIDTH - 1) {
          std::cout << '#';
        } else if (j == 0) {
          std::cout << std::endl << '#';
        } else if (i == SCREEN_HEIGHT - 1) {
          std::cout << '#';
        } else {
          std::cout << ' ';
        }
        // Draw the snake
        if (i == snakeHeadXPos && j == snakeHeadYPos) {
          std::cout << 'P';
        }
      }
    }
    std::cout << std::endl;
    absl::SleepFor(absl::Seconds(5));
  }
}

}  // namespace snake

int main() {
  snake::StartGame();
  return 0;
}
