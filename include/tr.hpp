// Author:   timebug
// License:  BSD

#ifndef TR_HPP
#define TR_HPP

template <typename T>
Matrix<T> tr( const Matrix<T> &A ) {
    Matrix<T> B(A.cols(),A.rows());
    for( int i = 0; i < A.rows(); ++i ) {
        for ( int j = 0; j < A.cols(); ++j ) {
            B[j][i] = A[i][j];
        }
    }
          
    return B;
}

#endif
