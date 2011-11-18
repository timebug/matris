// Author:   timebug
// License:  BSD

#ifndef RANK_HPP
#define RANK_HPP

template <typename T>
int rank( const Matrix<T> &A ) {
    Matrix<T> B = rref(A);
    double eps = 1.0e-10;
    int count = 0;
     
    for (int i = 0; i < B.rows(); ++i) {
        for (int j = 0; j < B.cols(); ++j) {
            if (abs(B[i][j]) > eps) {
                count++;
                break;
            }
        }
    }

    return count;
}

#endif
