#include <iostream>

#include <SDL.h>

int main(int, char **)
{
  const int window_width
  { 800 };

  const int window_height
  { 800 };

  SDL_Init(SDL_INIT_EVERYTHING);

  SDL_Window* window
  { nullptr };

  SDL_Renderer* renderer
  { nullptr };

  SDL_CreateWindowAndRenderer(window_width, window_height, 0, &window, &renderer);

  SDL_RenderSetScale(renderer, 2, 2);
  
  bool looped
  { true };
  
  
  
  while (looped)
  {
    SDL_Event event;
    
    while (SDL_PollEvent(&event))
    {
      switch (event.type)
      {
        case SDL_QUIT:
          looped = false;
          break;    
          
        case SDL_KEYDOWN:
          switch(event.key.keysym.scancode)
          {
            case SDL_SCANCODE_ESCAPE:
              looped = false;
              break;    
            default:
              break;
          }
        default:
            break;
      }
    }
  }

  std::cout << "SDL seems to work!" << std::endl;

  return 0;
}
