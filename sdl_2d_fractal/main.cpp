#include <iostream>

#include <SDL.h>

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
  
  const float real_min
  { -1.5f };
  
  const float real_max
  { 1.5f };
  
  const float real_span
  { real_max - real_min };
  
  const float real_delta
  { real_span/float{ window_width }};
  
  const float imag_min
  { -1.5f };
  
  const float imag_max
  { 1.5f };
  
  const float imag_span
  { imag_max - imag_min };
  
  const float imag_delta
  { imag_span/float{ window_height }};
  
  const float f_delta_max
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
      const float real
      { real_min + static_cast<float>(x)*real_delta };
            
      for (int y { 0 }; y <= window_height; ++y)
      {
        const float imag
        { imag_max - static_cast<float>(y)*imag_delta };
        
        float f_real
        { 0.0f };
        
        float f_imag
        { 0.0f };
        
        float f_real_
        { 0.0f };
        
        float f_imag_
        { 0.0f };
        
        float f_delta_real
        { 0.0f };
        
        float f_delta_imag
        { 0.0f };
        
        float f_delta
        { 0.0f };
        
        int iter
        { 0 };
        
        while ((f_delta <= f_delta_max) && (iter < iter_max))
        {        
          tester(real, imag, f_real, f_imag, f_real_, f_imag_);
          
          // multiplex(real, imag, f_real_, f_imag_);
          
          f_delta_real = f_real_ - f_real;
          f_delta_imag = f_imag_ - f_imag;
          
          f_delta = f_delta_real*f_delta_real + f_delta_imag*f_delta_imag;     
          
          f_real = f_real_;
          f_imag = f_imag_;
          
          ++iter;     
        }
        
        const int grey
        { iter * mult};
        
        
                        
        SDL_SetRenderDrawColor(renderer, grey, 0, 0, 255);
        
        SDL_RenderDrawPoint(renderer, x, y);
        
      }
    }
    
    
    
    SDL_RenderPresent(renderer);
  }

  std::cout << "SDL seems to work!" << std::endl;

  return 0;
}

