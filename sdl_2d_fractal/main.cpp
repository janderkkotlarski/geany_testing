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
    
    SDL_SetRenderDrawColor(renderer, 255, 127, 0, 255);
    
    /*
    
    for (int x{ 0 }; x <= window_width; ++x)
    {
      for (int y{ 0 }; y <= window_height; ++y)
      {
        int red
        { static_cast<int>(255.0f*static_cast<float>(x)/static_cast<float>(window_width))};
        
        int blue
        { static_cast<int>(255.0f*static_cast<float>(y)/static_cast<float>(window_width))};
        
        SDL_SetRenderDrawColor(renderer, red, 127, blue, 255);
        
        SDL_RenderDrawPoint(renderer, x, y);
      }
    }
     
    */
    
    for (int x { 0 }; x <= window_width; ++x)
    {
      const float real
      { real_min + static_cast<float>(x)*real_delta };
      
      const int red
      { static_cast<int>(255.0f*real*real) };
      
      for (int y { 0 }; y <= window_height; ++y)
      {
        const float imag
        { imag_max - static_cast<float>(y)*imag_delta };
        
        const int blue
        { static_cast<int>(255.0f*imag*imag) };
        
        SDL_SetRenderDrawColor(renderer, red, 127, blue, 255);
        
        SDL_RenderDrawPoint(renderer, x, y);
        
      }
    }
    
    
    
    SDL_RenderPresent(renderer);
  }

  std::cout << "SDL seems to work!" << std::endl;

  return 0;
}

