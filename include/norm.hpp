// Author:   timebug
// License:  BSD

#ifndef NORM_HPP
#define NORM_HPP

template <typename T>
T norm( const Matrix<T> &A, string p="2" ) {
    int m = A.rows();
    int n = A.cols();

    T nm = 0, tmp;
          
    if (p == "1") {
        for (int j = 0; j < n; ++j) {
            tmp = 0;
            for (int i = 0; i < m; ++i) {
                tmp += abs(A[i][j]);
            }
            if (tmp > nm) {
                nm = tmp;
            }
        }
    }

    if (p == "2") {
        for (int j = 0; j < n; ++j) {
            tmp = 0;
            for (int i = 0; i < m; ++i) {
                tmp += pow((double)A[i][j],2.0);
            }
            nm += tmp;
        }

        nm = sqrt((double)nm);
    }

    if (p == "inf") {
        for (int i = 0; i < m; ++i) {
            tmp = 0;
            for (int j = 0; j < n; ++j) {
                tmp += abs(A[i][j]);
            }
            if(tmp > nm) {
                nm = tmp;
            }
        }
    }

    return nm;
}

#endif
