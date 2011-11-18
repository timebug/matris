// Author:   timebug
// License:  BSD

#ifndef LU_HPP
#define LU_HPP

template <typename T>
vector< Matrix<T> > lu( const Matrix<T> &A ) {
          
    int m = A.rows();
    int n = A.cols();
          
    double eps = 1.0e-10;
    int count = 0;

    Matrix<T> L(m,m);
    Matrix<T> U(A);
    Matrix<T> P(m,m);

    Matrix<T> F(1,1);

    L = 1;
    P = 1;

    vector< Matrix<T> > V;

    for (int i = 0; i < n-1; ++i) {

        T maxi = 0, tmpi;
        int nth;
          
        for (int j = i; j< m; ++j) {
            if( (tmpi = abs(U[j][i])) > maxi ) {
                maxi = tmpi;
                nth = j;
            }
        }

        if(maxi > eps) {
               
            if(nth > i) {
                swap(rows(U)[nth],rows(U)[i]);
                swap(rows(P)[nth],rows(P)[i]);
                count++;
            }
          
            for (int j = i+1; j < m; ++j) {
                L[j][i] = U[j][i]/U[i][i];
                U[j][i] = 0;
                for (int k = i+1; k < n; ++k) {
                    U[j][k] -= L[j][i]*U[i][k];
                    if(abs(U[j][k]) < eps) U[j][k] = 0;
                }
            }

        }

    }

    F = count;
          
    V.push_back(L);
    V.push_back(U);
    V.push_back(P);
    V.push_back(F);

    return V;
}

#endif
