#ifndef SP_VECTOR3_HPP
#define SP_VECTOR3_HPP

#include "precision.h"
#include <iostream>


namespace spear {

	class Vector3 {

	public:

		/** Value of x axis*/
		real x;
		/** Value of y axis*/
		real y;
		/** Value of z axis*/
		real z;


	public:

		/** The default constructor creates a zero vector. */
		Vector3() : x((real)0), y((real)0), z((real)	0) {}
		/** Constructor creates vector with given value */
		Vector3(const real a, const real b, const real c) : x(a), y(b), z(c) {}
		/** Constructor creates vector with given vector */
		Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.x) {}
		Vector3(Vector3&& v) noexcept = default;

		Vector3& operator= (const Vector3& v) {
			x = v.x;
			y = v.y;
			z = v.z;
			return *this;
		}
		Vector3& operator= (Vector3&& v) = default;

		/** Adds given vector to this, scaled by given amount */
		void addScaledVector(const Vector3& vector, const real scale) {

			x += vector.x * scale;
			y += vector.y * scale;
			z += vector.z * scale;

		}

		/** Flips all component of this */
		void invert() {

			x = -x;
			y = -y;
			z = -z;

		}

		real magnitude() const { return real_sqrt(x * x + y * y + z * z); }
		real squaredMagnitude() const { return x * x + y * y + z * z; }
		real inverseMagnitude() const { return real_inverse_sqrt(x * x + y * y + z * z); }

		/** Turns a non-zero vector into a vector of unit length. */
		void normalise() {
			if (squaredMagnitude() > 0) {
				(*this) *= ((real)1) * inverseMagnitude();
			}
		}

		real scalarProduct(const Vector3& v) const { return (x * v.x) + (y * v.y) + (z * v.z); }
		Vector3 vectorProduct(const Vector3& v) const {
			return Vector3(	(y * v.z) - (z * v.y),
							(z * v.x) - (x * v.z),
							(z * v.y) - (y * v.x) );
		}

		bool operator== (const Vector3& v) const { return (x == v.x) && (y == v.y) && (z == v.z); }
		bool operator!= (const Vector3& v) const { return (x != v.x) || (y != v.y) || (z != v.z); }

		Vector3 operator+ (const Vector3& v) const { return Vector3((x + v.x), (y + v.y), (z + v.z)); }
		Vector3& operator+= (const Vector3& v) {
			x += v.x;
			y += v.y;
			z += v.z;
			return *this;
		}
		Vector3 operator- (const Vector3& v) const { return Vector3((x - v.x), (y - v.y), (z - v.z)); }
		Vector3& operator-= (const Vector3& v) {
			x -= v.x;
			y -= v.y;
			z -= v.z;
			return *this;
		}

		/** returns Scalarproduct */
		real operator* (const Vector3& v) const {
			return (x * v.x) + (y * v.y) + (z * v.z);
		}

		/** multyplyies component of this */
		Vector3 operator* (const real r) const { return Vector3(x * r, y * r, z * r); }
		Vector3& operator*= (real r) {
			x *= r;
			y *= r;
			z *= r;
			return *this;
		}

		/** returns Vectorproduct */
		Vector3 operator% (const Vector3& v) const {
			return Vector3(	(y * v.z) - (z * v.y),
							(z * v.x) - (x * v.z),
							(x * v.y) - (y * v.x));
		}
		Vector3& operator%= (const Vector3& v) {
			x = (y * v.z) - (z * v.y);
			y = (z * v.x) - (x * v.z);
			z = (x * v.y) - (y * v.x);
			return *this;
		}


	};

	std::ostream& operator<< (std::ostream& o, const Vector3& vec) {

		std::cout << "[" << vec.x << ", " << vec.y << ", " << vec.z << "]";

		return o;
	}

}

#endif //SP_VECTOR3_HPP