#include <iostream>

#include <SDL2/SDL.h>

int main(int, char **)
{
  video cassette;

  // cassette.display();

  const int window_width
  { 800 };

  const int window_height
  { 800 };

  SDL_Init(SDL_INIT_EVERYTHING);

  // SDL_Init(SDL _INIT_EVERYTHING);

  SDL_Window* window
  { nullptr };

  SDL_Renderer* renderer
  { nullptr };

  SDL_CreateWindowAndRenderer(window_width, window_height, 0, &window, &renderer);

  SDL_RenderSetScale(renderer, 2, 2);

  std::cout << "Hello World!" << std::endl;

  return 0;
}
