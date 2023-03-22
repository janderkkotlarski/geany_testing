// #include "complexinates.h"

#include <iostream>

#include <SDL.h>

std::pair <float, float> complex_negate(const std::pair <float, float> &complex)
{ return std::pair <float, float>{ -complex.first, -complex.second }; }

void multiplex(const float f_real, const float f_imag,
               float &f_real_, float &f_imag_)
{
  const float g_real
  { f_real*f_real_ - f_imag*f_imag_ };
  
  const float g_imag
  { f_imag*f_real_ + f_real*f_imag_ };
  
  f_real_ = g_real;
  f_imag_ = g_imag;
}

void multiplex_p(const float f_real, const float f_imag,
               float &f_real_, float &f_imag_,
               const int power)
{
  if (power >= 1)
  {
    multiplex_p(f_real, f_imag, f_real_, f_imag_, power - 1);
    
    multiplex(f_real, f_imag, f_real_, f_imag_);
  }
}

void mandel(const float real, const float imag,
            const float f_real, const float f_imag,
            float &f_real_, float &f_imag_)
{
  f_real_ = f_real*f_real - f_imag*f_imag + real;
  f_imag_ = 2.0f*f_real*f_imag + imag;
}

void tester(const float real, const float imag,
            const float f_real, const float f_imag,
            float &f_real_, float &f_imag_)
{
  multiplex_p(f_real, f_imag, f_real_, f_imag_, 5);
  
  f_real_ += real;
  f_imag_ += imag;
}



int main(int, char **)
{
  const int window_width
  { 800 };

  const int window_height
  { 800 };
  
  std::pair <float, float> complex_now
  { 0.0f, 0.0f };
  
  const std::pair <float, float> complex_min 
  { -1.5f, -1.5f };
  
  const std::pair <float, float> complex_max 
  { 1.5f, 1.5f };
  
  const std::pair <float, float> complex_span
  { complex_max.first - complex_min.first, complex_max.second - complex_min.second };
  
  const std::pair <float, float> complex_delta
  { complex_span.first/float{ window_width }, complex_span.second/float{ window_height } };  
  
  const float delta_2_max
  { 10.0f };
  
  const int iter_max
  { 255 };
  
  const int mult
  { 255 / iter_max };
  
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
    
    
    
    for (int x { 0 }; x <= window_width; ++x)
    {
      complex_now.first = complex_min.first + static_cast<float>(x)*complex_delta.first;
            
      for (int y { 0 }; y <= window_height; ++y)
      {
        complex_now.second = complex_max.second - static_cast<float>(y)*complex_delta.second;
        
        std::pair <float, float> complex_1st
        { 0.0f, 0.0f };
        
        std::pair <float, float> complex_2nd
        { 0.0f, 0.0f };
        
        std::pair <float, float> c_delta
        { 0.0f, 0.0f };
                
        float f_delta_real
        { 0.0f };
        
        float f_delta_imag
        { 0.0f };
        
        float c_delta_2
        { 0.0f };
        
        int iter
        { 0 };
        
        /*
        while ((c_delta_2 <= delta_2_max) && (iter < iter_max))
        {        
          tester(complex_now.first, complex_now.second,
                 complex_1st.first, complex_1st.first,
                 complex_2nd.first, complex_2nd.second);
          
          // multiplex(real, imag, f_real_, f_imag_);
          
          f_delta_real = complex_2nd.first - complex_1st.first;
          f_delta_imag = complex_2nd.second - complex_1st.second;
          
          // c_delta = complex_2nd - complex_1st;
          
          
          
          c_delta_2 = f_delta_real*f_delta_real + f_delta_imag*f_delta_imag;     
          
          complex_1st = complex_2nd;
          
          ++iter;     
        }
        
        const int grey
        { iter * mult};
        */        
                        
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        
        SDL_RenderDrawPoint(renderer, x, y);
        
      }
    }
    
    
    
    SDL_RenderPresent(renderer);
  }

  std::cout << "SDL seems to work!" << std::endl;

  return 0;
}

