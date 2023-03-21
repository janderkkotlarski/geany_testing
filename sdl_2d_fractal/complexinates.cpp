#include "complexinates.h"

#include <cmath>

complexinates::complexinates(const float real, const float imag, const bool polar)
{
  if (polar)
  {
    m_theta = real;
    m_phi = imag;
  }
  
  {
    m_real = real;
    m_imag = imag;
  }  
}

void complexinates::polar2carte()
{
  const float absol
  { std::exp(m_theta) };
}
