#ifndef COMPLEXINATES
#define COMPLEXINATES

class complexinates
{
  private:
  
    double m_real
    { 0.0f };
    
    double m_imag
    { 0.0f };
    
    double m_theta
    { 0.0f };
    
    double m_phi
    { 0.0f };
    
    bool m_polar
    { false };
  
  public:
  
    complexinates(const double real, const double imag, const double polar);
    
    void polar2carte();
};

#endif // COMPLEXINATES
