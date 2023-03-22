#include "complexinates.h"

#include <cmath>

complexinates::complexinates(const double real, const double imag, const bool polar)
{
  if (polar)
  {
    m_theta = real;
    m_phi = imag;
  }
  else
  {
    m_real = real;
    m_imag = imag;
  }
}

double complexinates::get_real() noexcept
{ return m_real; }

void complexinates::polar2carte()
{
  const double abso
  { exp(m_theta) };
  
  m_real = abso*cos(m_phi);
  
  m_imag = abso*sin(m_phi);  
}
