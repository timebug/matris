// Author:   timebug
// License:  BSD

#ifndef POWER_METHOD_HPP
#define POWER_METHOD_HPP

template <typename T>
vector< Matrix<T> > power_method( const Matrix<T> &A , double eps ) {
    // argument must be a square matrix
    assert(A.rows() == A.cols());

    int n = A.rows();

    Matrix<T> u = A.cols(0);
    Matrix<T> x(n,1);
    Matrix<T> v(n,1);
     
    T lambda = 1e100;

    while(1) {
        v = A*u;
          
        T max_v = 0;
        for (int i = 0; i < n; ++i) {
            if( abs(v[i][0]) > abs(max_v) ) {
                max_v = v[i][0];
            }
        }

        x = u;
        u = (1.0/max_v)*v;
          
        if( abs(lambda-max_v) < eps ) break;
          
        lambda = max_v;
    }

    Matrix<T> la(1,1,lambda);
     
    vector< Matrix<T> > V;
    V.push_back(la);
    V.push_back(x);

    return V;
}

#endif
