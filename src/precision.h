#ifndef SP_PRECISION_H
#define SP_PRECISION_H

#include "spear_config.h"
#include "experimentMath.hpp"
#include <math.h>

namespace spear {


#ifdef SP_EXPERIMENTAL_QUAKE_FASTINVSQRT
#	define sp_invsqrtf Q_invsqrt_f
#	define sp_invsqrt Q_invsqrt
#else
	inline float invsqrt_f(const float x) { return 1.0F / sqrtf(x); }
	inline double invsqrt(const double x) { return 1.0 / sqrt(x); }
#	define sp_invsqrtf invsqrt_f
#	define sp_invsqrt invsqrt
#endif // SP_EXPERIMENTAL_QUAKE_FASTINVSQRT

#ifdef PS_SINGLE_PRECISION
	typedef float real;
#	define real_sqrt sqrtf
#	define real_inverse_sqrt sp_invsqrtf

#else
	typedef double real;
#	define real_sqrt sqrt
#	define real_inverse_sqrt sp_invsqrt

#endif // PS_SINGLE_PRECISION

}

#endif