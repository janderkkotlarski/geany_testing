#include "raylib.h"

int main()
{
  SetConfigFlags(FLAG_MSAA_4X_HINT);  // Enable Multi Sampling Anti Aliasing 4x (if available)
  InitWindow(800, 800, "raylib with geany");

  SetTargetFPS(60);
  
  while (!WindowShouldClose())            // Detect window close button or ESC key
  {
    BeginDrawing();

      ClearBackground(BLACK);

      DrawFPS(20, 20);

    EndDrawing();
  }
}
