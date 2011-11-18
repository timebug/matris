// Author:   timebug
// License:  BSD

#ifndef RREF_HPP
#define RREF_HPP

template <typename T>
Matrix<T> rref( const Matrix<T> &A ) {
     
    int m = A.rows();
    int n = A.cols();
          
    double eps = 1.0e-10;

    Matrix<T> B(A);

    int p = 0;

    for (int i = 0; i < n; ++i) {

        T maxi = 0, tmpi;
        int nth;
          
        for (int j = p; j< m; ++j) {
            if( (tmpi = abs(B[j][i])) > maxi ) {
                maxi = tmpi;
                nth = j;
            }
        }

        if(maxi > eps) {
               
            if(nth > p) {
                swap(rows(B)[nth],rows(B)[p]);
            }
          
            for (int j = p+1; j < m; ++j) {
                T tmp = B[j][i]/B[p][i];
                B[j][i] = 0;
                for (int k = i+1; k < n; ++k) {
                    B[j][k] -= tmp*B[p][k];
                    if(abs(B[j][k]) < eps) B[j][k] = 0;
                }
            }
               
            p++;
        } 
    }


    for (int i = 0; i < m; ++i) {
        int p = -1;
        for (int j = 0; j < n; ++j) {
            if (abs(B[i][j]) > eps) {
                p = j;
                break;
            }
        }

        if(p >= 0) {
            T tmp = B[i][p];
            B[i][p] = 1;
            for (int j = p+1; j < n; ++j) {
                B[i][j] /= tmp;
            }
          
            for (int j = i-1; j >=0; --j) {
                tmp = B[j][p];
                B[j][p] = 0;
                for (int k = p+1; k < n; ++k) {
                    B[j][k] -= tmp*B[i][k];
                    if(abs(B[j][k]) < eps) B[j][k] = 0;
                }
            }
        }
    }

    return B;
}

#endif
