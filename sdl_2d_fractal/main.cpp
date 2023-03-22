#include "complexinates.h"

#include <iostream>

#include <SDL.h>

int main(int, char **)
{
  const int window_width
  { 800 };

  const int window_height
  { 800 };
  
  std::pair <double, double> complex_now
  { 0.0f, 0.0f };
  
  const std::pair <double, double> complex_min 
  { 0, 0 };
  
  const std::pair <double, double> complex_max 
  { 255, 255 };
  
  const std::pair <double, double> complex_span
  { complex_max.first - complex_min.first, complex_max.second - complex_min.second };
  
  const std::pair <double, double> complex_delta
  { complex_span.first/double{ window_width }, complex_span.second/double{ window_height } };  
     
  const int iter_max
  { 255 };  
    
  SDL_Init(SDL_INIT_EVERYTHING);

  SDL_Window* window
  { nullptr };

  SDL_Renderer* renderer
  { nullptr };

  SDL_CreateWindowAndRenderer(window_width + 1, window_height + 1, 0, &window, &renderer);

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
    
    int red
    { 0 };
    
    int green
    { 0 };
    
    int blue
    { 63 };
    
    for (int x { 0 }; x <= window_width; ++x)
    {
      complex_now.first = complex_min.first + static_cast<double>(x)*complex_delta.first;
      
      green = static_cast<int>(complex_now.first);
            
      for (int y { 0 }; y <= window_height; ++y)
      {
        complex_now.second = complex_max.second - static_cast<double>(y)*complex_delta.second;
        
        red = static_cast<int>(complex_now.second);
        
               int iter
        { 0 };
        
        while (iter < iter_max)
        {
          ++iter;
        }
        
        blue = iter;
    
        SDL_SetRenderDrawColor(renderer, red, green, blue, 255);
        
        SDL_RenderDrawPoint(renderer, x, y);
        
      }
    }
    
    
    
    SDL_RenderPresent(renderer);
  }

  std::cout << "SDL seems to work!" << std::endl;

  return 0;
}

