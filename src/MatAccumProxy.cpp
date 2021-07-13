namespace spear {
      MatAccumProxy::MatAccumProxy(const Matrix3& a, const Matrix3& b){
      mat = a;
      for(int i = 0 ; i < 3 ; i++) {
        for(int j = 0 ; j < 3 ; j++) {
          mat[i][j] += b[i][j];
        }
      }
    }
    
    MatAccumProxy MatAccumProxy::operator+(const Matrix3& oth) && {
      for(int i = 0 ; i < 3 ; i++) {
        for(int j = 0 ; j < 3 ; j++) {
          mat[i][j] += b[i][j];
        }
      }
    }
    
    Matrix3 MatAccumProxy::operator Matrix() const && {
      return mat;
    }
}