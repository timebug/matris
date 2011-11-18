// Author:   timebug
// License:  BSD

#ifndef DIAG_HPP
#define DIAG_HPP

template <typename T>
Matrix<T> diag( const Matrix<T> &A ) {
    int n = A.rows() < A.cols() ? A.rows() : A.cols();
    Matrix<T> d(n,1);
    for (int i = 0; i < n; ++i) {
        d[i][0] = A[i][i];
    }

    return d;
}

#endif
