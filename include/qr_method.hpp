// Author:   timebug
// License:  BSD

#ifndef QR_METHOD_HPP
#define QR_METHOD_HPP

template <typename T>
Matrix<T> qr_method( const Matrix<T> &A , double eps ) {
    // argument must be a square matrix
    assert(A.rows() == A.cols());

    Matrix<T> B(A);

    int n = A.rows();

    for (int i = 0; i < n-2; ++i) {
        int xn = n-i-1;
               
        Matrix<T> x(xn,1);
               
        for (int j = 0; j < xn; ++j) {
            x[j][0] = B[i+j+1][i];
        }

        T a = norm(x);
        T b = a*(a-x[0][0]);

        Matrix<T> v(x);

        v[0][0] -= a;
               
        Matrix<T> H(xn,xn);
        Matrix<T> I(xn,xn);
               
        I = 1;

        if(b) H = I - (1/b)*v*tr(v);
        else H = I;

        Matrix<T> Hk(n,n);
        Hk = 1;

        for (int j = 0; j < xn; ++j) {
            for (int k = 0; k < xn; ++k) {
                Hk[j+i+1][k+i+1] = H[j][k];
            }
        }

        B = Hk*B*Hk;
    }
    while(1) {
        Matrix<T> tB(B);
          
        for (int i = 0; i < n-1; ++i) {

            Matrix<T> G(n,n);
            G = 1;

            int j = i+1;
            T r = sqrt( B[i][i]*B[i][i] + B[j][i]*B[j][i] );
            T c = B[i][i]/r;
            T s = B[j][i]/r;
               
            G[i][i] = c;
            G[i][j] = s;
            G[j][i] = s;
            G[j][j] = -c;

            B = G*B*G;
        }

        bool flag = true;
        for (int i = 0; i < n; ++i) {
            if (abs(B[i][i]-tB[i][i]) >= eps) {
                flag = false;
                break;
            }
        }

        if (flag) break;
    }

    Matrix<T> L(n,1);
     
    for (int i = 0; i < n; ++i) {
        L[i][0] = B[i][i];
    }

    return L;
}

#endif
