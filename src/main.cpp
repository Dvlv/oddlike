#include "constants.h"
#include "raylib-cpp.hpp"

void update() {}

void draw() {
  BeginDrawing();

  ClearBackground(RAYWHITE);

  EndDrawing();
}

int main() {
  raylib::Window window(WINDOW_WIDTH, WINDOW_HEIGHT, "Oddlike");

  SetTargetFPS(FPS);

  while (!window.ShouldClose()) {
    update();
    draw();
  }

  return 0;
}
