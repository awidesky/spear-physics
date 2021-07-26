#ifndef SP_MATRIX4_HPP
#define SP_MATRIX4_HPP


#include "core.hpp"
#include <iostream>


namespace spear {

	class Matrix3 {

	public:


		/*
		* data[0][0] data[0][1] data[0][2] 
		* data[1][0] data[1][1] data[1][2] 
		* data[2][0] data[2][1] data[2][2] 
		*/

		/* values of the matrix */
		real data[3][3];

	public:

		/** The default constructor creates a identical matrix. */
		Matrix3() : data{ {(real)1, (real)0, (real)0}, {(real)0, (real)1, (real)0}, {(real)0, (real)0, (real)1} } {};

		/** Constructor creates a matrix with given array data. */
		Matrix3(const real (&_data)[3][3]) {
			for(int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					data[i][j] = _data[i][j];
				}
			}
		};

		/** Constructor creates a matrix with given initializer_list. */
		Matrix3(const std::initializer_list<std::initializer_list<real>>& list) {
			/* https://stackoverflow.com/questions/48243044/how-do-i-initialize-with-a-2-dimensional-initializer-list */
			auto it = list.begin();         // iterate through outer list 
			for (int i = 0; i < 3; i++, it++) {
				std::copy(it->begin(), it->end(), data[i]); // copy current inner list
			}
		};
		
		/** The default constructor creates (given value) * (identical matrix). */
		Matrix3(const real value) : data { {value, (real)0, (real)0}, { (real)0, value, (real)0 }, { (real)0, (real)0, value } } {};

		/** Constructor creates matrix with given column vector */
		Matrix3(const Vector3& a, const Vector3& b, const Vector3& c) {
			data[0][0] = a.x; data[0][1] = b.x; data[0][2] = c.x;
			data[1][0] = a.y; data[1][1] = b.y; data[1][2] = c.y;
			data[2][0] = a.z; data[2][1] = b.z; data[2][2] = c.z;
		}


		/** Copy constructor */
		Matrix3(const Matrix3& mat) {
			Matrix3(mat.data);
		}
		/** Copy assingment */
		Matrix3& operator= (const Matrix3& m) {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					data[i][j] = m.data[i][j];
				}
			}
			return *this;
		}

		/** move constructor */
		Matrix3(Matrix3&& mat) noexcept = default;
		/** move assingment */
		Matrix3& operator= (Matrix3&& mat) noexcept = default;

		const real* operator[](int index) const {
			return data[index];
		}

		real* operator[](int index) {
			return data[index];
		}

		Vector3 operator* (Vector3& v) const {
			
			return Vector3(	data[0][0] * v.x + data[0][1] * v.y + data[0][2] * v.z,
							data[1][0] * v.x + data[1][1] * v.y + data[1][2] * v.z,
							data[2][0] * v.x + data[2][1] * v.y + data[2][2] * v.z);

		}

		Matrix3 operator* (Matrix3& mat) const {

			Matrix3 result{(real)0};

			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					for (int k = 0; k < 3; k++)
						result[i][k] += data[i][j] * mat.data[j][k];

			return result;
		}

		Matrix3& operator*= (Matrix3& mat) {

			*this = *this * mat;
			return *this;
		}

		Matrix3 operator+ (Matrix3& mat) {
			Matrix3 result{ 0 };

			for (int i = 0; i < 3; i++) 
				for (int j = 0; j < 3; j++) 
					result[i][j] = data[i][j] + mat.data[i][j];

			return result;
		}

		Matrix3& operator+= (Matrix3& mat) {
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					data[i][j] += mat.data[i][j];

			return *this;
		}

		Matrix3& operator- (Matrix3& mat) {
			Matrix3 result{ 0 };

			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					result[i][j] = data[i][j] - mat.data[i][j];

			return result;
		}

		Matrix3& operator-= (Matrix3& mat) {
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					data[i][j] -= mat.data[i][j];

			return *this;
		}
	};

	std::ostream& operator<< (std::ostream& o, const Matrix3& mat) {

		std::cout	<< mat[0][0] << " " << mat[0][1] << " " << mat[0][2] << "\n"
					<< mat[1][0] << " " << mat[1][1] << " " << mat[1][2] << "\n"
					<< mat[2][0] << " " << mat[2][1] << " " << mat[2][2] << "\n";

		return o;
	}


}

#endif // !SP_MATRIX4_HPP