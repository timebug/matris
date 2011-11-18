// Author:   timebug
// License:  BSD

#ifndef GRAM_SCHMIDT_MODIFIED_HPP
#define GRAM_SCHMIDT_MODIFIED_HPP

template <typename T>
vector< Matrix<T> > gram_schmidt_modified( const Matrix<T> &A ) {
    int n = A.cols();
    int m = A.rows();

    vector< Matrix<T> > a,q;

    Matrix<T> Q(m,n);
    Matrix<T> R(n,n);

    for (int i = 0; i < n; ++i) {
        Matrix<T> tmp = A.cols(i);
        a.push_back(tmp);
        q.push_back(tmp);
    }

    for (int k = 0; k < n; ++k) {
        R[k][k] = norm(a.at(k));
        q.at(k) = (1/R[k][k])*a.at(k);

        for (int j = k+1; j < n; ++j) {
            Matrix<T> tmp = tr(q.at(k))*a.at(j);
            R[k][j] = tmp[0][0];
            a.at(j) = a.at(j) - R[k][j]*q.at(k);
        }
    }

    for (int i = 0; i < n; ++i) {
        Matrix<T> tmp = q.at(i);
        for (int j = 0; j < m; ++j) {
            Q[j][i] = tmp[j][0];
        }
    }

    vector< Matrix<T> > V;
    V.push_back(Q);
    V.push_back(R);

    return V;
}

#endif
