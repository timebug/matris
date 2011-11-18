// Author:   timebug
// License:  BSD

#ifndef LEAST_SQUARES_HPP
#define LEAST_SQUARES_HPP

template <typename T>
Matrix<T> least_squares( const Matrix<T> &A, const Matrix<T> &b ) {
    int m = A.rows();
    int n = A.cols();
     
    vector< Matrix<T> > V;
     
    V = qr(A);
     
    Matrix<T> Q = V.at(0); // mxm
    Matrix<T> R = V.at(1); // mxn
     
    Matrix<T> Q1(m,n);
    Matrix<T> R1(n,m);

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            Q1[i][j] = Q[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; ++j) {
            R1[i][j] = R[i][j];
        }
    }

    Matrix<T> c1 = tr(Q1)*b; // nx1 = (nxm)*(mx1)

    Matrix<T> x = guassian_elimination(R1,c1);

    return x;
}

#endif
