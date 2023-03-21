#ifndef COMPLEXINATES
#define COMPLEXINATES

class complexinates
{
  private:
  
    float m_real
    { 0.0f };
    
    float m_imag
    { 0.0f };
    
    float m_theta
    { 0.0f };
    
    float m_phi
    { 0.0f };
    
    bool m_polar
    { false };
  
  public:
  
    complexinates(const float real, const float imag, const bool polar);
    
    void polar2carte();
};

#endif // COMPLEXINATES
