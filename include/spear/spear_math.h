#ifndef SP_SPEAR_MATH_H
#define SP_SPEAR_MATH_H

#include "spear_config.h"
#include <math.h>
// include FPOptimizedMath headers
namespace spear {
  
  #ifdef SP_USE_QUAKE_FASTINVSQRT
  #include <stdint.h> 
  
  float Q_invsqrt_f(const float number) /* https://en.wikipedia.org/wiki/Fast_inverse_square_root */
  {
    uint32_t i;
    float x2, y;
    const float threehalfs = 1.5F;
    
    x2 = number * 0.5F;
    y = number;
    i = *(uint32_t*)&y;                       // evil floating point bit level hacking
    i = 0x5F375A86 - (i >> 1);               // what the fuck? 
    y = *(float*)&i;
    y = y * (threehalfs - (x2 * y * y));
    
    return y;
  }
  
  double Q_invsqrt(const double number) /* https://en.wikipedia.org/wiki/Fast_inverse_square_root */
  {
    uint64_t i;
    double x2, y;
    const double threehalfs = 1.5;
    
    x2 = number * 0.5;
    y = number;
    i = *(uint64_t*)&y;                       // evil floating point bit level hacking
    i = 0x5FE6EB50C7B537A9 - (i >> 1);               // what the fuck? 
    y = *(double*)&i;
    y = y * (threehalfs - (x2 * y * y));
    
    return y;
  }
  
  #	define sp_invsqrtf Q_invsqrt_f
  #	define sp_invsqrt Q_invsqrt
  #else
  float invsqrt_f(const float x) { return 1.0F / sqrtf(x); }
  double invsqrt(const double x) { return 1.0 / sqrt(x); }
  #	define sp_invsqrtf invsqrt_f
  #	define sp_invsqrt invsqrt
  #endif // SP_EXPERIMENTAL_QUAKE_FASTINVSQRT
}

#endif // SP_SPEAR_MATH_H
