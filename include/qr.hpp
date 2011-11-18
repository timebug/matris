// Author:   timebug
// License:  BSD

#ifndef QR_HPP
#define QR_HPP

template <typename T>
vector< Matrix<T> > qr( const Matrix<T> &A ) {
    int m = A.rows();
    int n = A.cols();

    Matrix<T> Q(m,m);
    Matrix<T> R(A);

    Q = 1;

    for (int j = 0; j < n; ++j) {

        int xn = m-j;
               
        Matrix<T> x(xn,1);
               
        for (int i = 0; i < xn; ++i) {
            x[i][0] = R[i+j][j];
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
               
        Matrix<T> Hk(m,m);
        Hk = 1;

        for (int i = 0; i < xn; ++i) {
            for (int k = 0; k < xn; ++k) {
                Hk[i+j][k+j] = H[i][k];
            }
        }

        Q = Q*Hk;
        R = Hk*R;

    }

    vector< Matrix<T> > V;
    V.push_back(Q);
    V.push_back(R);

    return V;
}

#endif
