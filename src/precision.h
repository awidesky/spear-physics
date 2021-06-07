#ifndef SP_PRECISION_H
#define SP_PRECISION_H

#include "spear_config.h"
#include "spear/spear_math.h"

#include <math.h>

namespace spear {

#ifdef PS_SINGLE_PRECISION
	typedef float real;
#	define real_sqrt sqrtf
#	define real_inverse_sqrt sp_invsqrtf

#else
	typedef double real;
#	define real_sqrt sqrt
#	define real_inverse_sqrt sp_invsqrt

#endif

}

#endif