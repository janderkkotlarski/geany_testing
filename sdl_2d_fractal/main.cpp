#include <iostream>

#include <SDL.h>

int main(int, char **)
{
  const int window_width
  { 800 };

  const int window_height
  { 800 };
  
  const float real_min
  { -1.0f };
  
  const float real_max
  { 1.0f };
  
  const float real_span
  { real_max - real_min };
  
  const float real_delta
  { real_span/float{ window_width }};
  
  const float imag_min
  { -1.0f };
  
  const float imag_max
  { 1.0f };
  
  const float imag_span
  { imag_max - imag_min };
  
  const float imag_delta
  { imag_span/float{ window_height }};
  
  
  

  SDL_Init(SDL_INIT_EVERYTHING);

  SDL_Window* window
  { nullptr };

  SDL_Renderer* renderer
  { nullptr };

  SDL_CreateWindowAndRenderer(window_width, window_height, 0, &window, &renderer);

  SDL_RenderSetScale(renderer, 1, 1);
  
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
    
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    
    SDL_RenderClear(renderer);
    
    SDL_SetRenderDrawColor(renderer, 255, 127, 0, 255);
    
    for (int x{ 0 }; x <= 798; ++x)
    {
      for (int y{ 200 }; y <= 400; ++y)
      {
        SDL_RenderDrawPoint(renderer, x, y);
      }
    }
    
    for (int x{ 1 }; x <= 799; ++x)
    {
      for (int y{ 401 }; y <= 600; ++y)
      {
        SDL_RenderDrawPoint(renderer, x, y);
      }
    }
    
    
    
    SDL_RenderPresent(renderer);
  }

  std::cout << "SDL seems to work!" << std::endl;

  return 0;
}

