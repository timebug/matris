// Author:   timebug
// License:  BSD

#ifndef COND_HPP
#define COND_HPP

template <typename T>
T cond( const Matrix<T> &A, string p="2" ) {
    T cd = norm(A,p)*norm(inv(A),p);
    return cd;
}

#endif
