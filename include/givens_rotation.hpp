// Author:   timebug
// License:  BSD

#ifndef GIVENS_ROTATION_HPP
#define GIVENS_ROTATION_HPP

template <typename T>
vector< Matrix<T> > givens_rotation( const Matrix<T> &A ) {
    // argument must be a square matrix
    assert(A.rows() == A.cols());

    int n = A.rows();

    Matrix<T> R(A);
    Matrix<T> Q(n,n);
    Q = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            Matrix<T> G(n,n);
            G = 1;

            T r = sqrt( R[i][i]*R[i][i] + R[j][i]*R[j][i] );
            T c = R[i][i]/r;
            T s = R[j][i]/r;
               
            G[i][i] = c;
            G[i][j] = s;
            G[j][i] = s;
            G[j][j] = -c;

            R = G*R;
            Q = G*Q;
        }
    }

    vector< Matrix<T> > V;
    V.push_back(Q);
    V.push_back(R);

    return V;
}

#endif
