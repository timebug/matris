// Author:   timebug
// License:  BSD

#ifndef INV_HPP
#define INV_HPP

template <typename T>
Matrix<T> inv( const Matrix<T> &A ) {
    // argument must be a square matrix
    assert(A.rows() == A.cols());

    int n = A.rows();
    double eps = 1.0e-10;

    Matrix<T> B(A);
    Matrix<T> I(n,n);
    I = 1;

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
            return Matrix<T>(n,n);
        }

        if(nth > i) {
            swap(rows(B)[nth],rows(B)[i]);
            swap(rows(I)[nth],rows(I)[i]);
        }
          
        for (int j = i+1; j < n; ++j) {
            T tmp = B[j][i]/B[i][i];
            B[j][i] = 0;
            for (int k = i+1; k < n; ++k) {
                B[j][k] -= tmp*B[i][k];
                if(abs(B[j][k]) < eps) B[j][k] = 0;
            }

            for (int k = 0; k < n; ++k) {
                I[j][k] -= tmp*I[i][k];
                if(abs(I[j][k]) < eps) I[j][k] = 0;
            }
        }
    }


    for (int i = 1; i < n; ++i) {
        for (int j = i-1; j >= 0; --j) {
            T tmp = B[j][i]/B[i][i];
            B[j][i] = 0;
            for (int k = i+1; k < n; ++k) {
                B[j][k] -= tmp*B[i][k];
                if(abs(B[j][k]) < eps) B[j][k] = 0;
            }

            for (int k = 0; k < n; ++k) {
                I[j][k] -= tmp*I[i][k];
                if(abs(I[j][k]) < eps) I[j][k] = 0;
            }
        }
    }


    for (int i = 0; i < n; ++i) {
        T tmp = B[i][i];
        B[i][i] = 1;

        for (int j = 0; j < n; ++j) {
            I[i][j] /= tmp;
        }
    }

    return I;
}

#endif
