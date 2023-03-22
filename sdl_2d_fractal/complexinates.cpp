#include "complexinates.h"

#include <cmath>

complexinates::complexinates(const double real, const double imag, const bool polar)
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
  const double absol
  { std::exp(m_theta) };
}
