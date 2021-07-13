
#ifndef SP_MATACCUMPROXY
#define SP_MATACCUMPROXY

#include Matrix3.hpp

namespace spear{
  
  class MatAccumProxy{
    public:
    MatAccumProxy(const Matrix3& a, const Matrix3& b);
    
    MatAccumProxy operator+(const Matrix3& oth) &&;
    
    Matrix3 operator Matrix3() const &&;
    
    private:
    Matrix3 mat;
    
  };
  
}

#endif
