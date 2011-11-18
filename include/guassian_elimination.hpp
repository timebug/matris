// Author:   timebug
// License:  BSD

#ifndef GUASSIAN_ELIMINATION_HPP
#define GUASSIAN_ELIMINATION_HPP

template <typename T>
Matrix<T> guassian_elimination(const Matrix<T> &A, const Matrix<T> &b) {
    int n = A.rows();
    double eps = 1.0e-10;

    Matrix<T> B(A);
    Matrix<T> a(b);
     
    for (int i = 0; i < n-1; ++i) {
        T maxi = 0, tmpi;
        int nth;
          
        for (int j = i; j< n; ++j) {
            if( (tmpi = abs(B[j][i])) > maxi ) {
                maxi = tmpi;
                nth = j;
            }
        }

        if(maxi < eps) {
            return Matrix<T>(n,1);
        }

        if(nth > i) {
            swap(rows(B)[nth],rows(B)[i]);
            swap(rows(a)[nth],rows(a)[i]);
        }
          
        for (int j = i+1; j < n; ++j) {
            T tmp = B[j][i]/B[i][i];
               
            for (int k = i+1; k < n; ++k) {
                B[j][k] -= tmp*B[i][k];
            }

            for (int k = 0; k < (int)a.cols(); ++k) {
                a[j][k] -= tmp*a[i][k];
            }
        
        }
    }
     

    for (int i = n-1; i >= 0; --i) {
        for ( int j = i+1; j < n; ++j) {
            for (int k = 0; k < (int)a.cols(); ++k) {
                a[i][k] -= B[i][j]*a[j][k];
            }
        }

        for (int j = 0; j < (int)a.cols(); ++j) {
            a[i][j] /= B[i][i];
            if (abs(a[i][j]) < eps) {
                a[i][j] = 0;
            }
        }
    }

    return a;
}

#endif
