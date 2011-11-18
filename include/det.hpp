// Author:   timebug
// License:  BSD

#ifndef DET_HPP
#define DET_HPP

template <typename T>
T det( const Matrix<T> &A ) {
    // argument must be a square matrix
    assert(A.rows() == A.cols());        

    int n = A.rows();
    vector< Matrix<T> > V;

    V = lu(A);

    if(V.empty()) return 0;
          
    Matrix<T> U = V.at(1);
    Matrix<T> F = V.at(3);

    int count = F[0][0];

    T value = U[0][0];

    for (int i = 1; i < n; ++i) {
        value *= U[i][i];
    }

    if(count%2) value = -value;
    if(!value) value = 0;

    return value;
}

#endif
