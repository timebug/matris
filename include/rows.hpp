// Author:   timebug
// License:  BSD

#ifndef ROWS_HPP
#define ROWS_HPP

template <typename T>
T** rows( const Matrix<T> &A ) {
    return A.data();
}

#endif
