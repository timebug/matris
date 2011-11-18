// Author:   timebug
// License:  BSD

#ifndef MATRIX_OPERATOR_HPP
#define MATRIX_OPERATOR_HPP

template <typename T>
Matrix<T> operator+( const Matrix<T> &A, const Matrix<T> &B ) {
    assert(A.rows() == B.rows());
    assert(A.cols() == B.cols());
          
    Matrix<T> C(A.rows(),A.cols());

    for( int i = 0; i < C.rows(); ++i ) {
        for ( int j = 0; j < C.cols(); ++j ) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    return C;
}

template <typename T>
Matrix<T> operator-( const Matrix<T> &A, const Matrix<T> &B ) {
    assert(A.rows() == B.rows());
    assert(A.cols() == B.cols());
          
    Matrix<T> C(A.rows(),A.cols());

    for( int i = 0; i < C.rows(); ++i ) {
        for ( int j = 0; j < C.cols(); ++j ) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }

    return C;
}

template <typename T>
Matrix<T> operator*( const Matrix<T> &A, const Matrix<T> &B ) {
    assert(A.cols() == B.rows());

    Matrix<T> C(A.rows(),B.cols());
    for( int i = 0; i < C.rows(); ++i ) {
        for ( int j = 0; j < C.cols(); ++j ) {
            for ( int k = 0; k < A.cols(); ++k ) {
                C[i][j] += A[i][k]*B[k][j];
            }
        }
    }

    return C;
} 

template <typename T>
Matrix<T> operator*( const T &alpha, const Matrix<T> &A ) {
          
    Matrix<T> C(A.rows(),A.cols());
    for( int i = 0; i < C.rows(); ++i ) {
        for ( int j = 0; j < C.cols(); ++j ) {
            for ( int k = 0; k < A.cols(); ++k ) {
                C[i][j] += alpha*A[i][k];
            }
        }
    }

    return C;
}

template <typename T>
istream& operator>>( istream &is, Matrix<T> &A ) {
    for ( int i = 0; i < A.rows(); ++i ) {
        for (int j = 0; j < A.cols(); ++j ) {
            is >> A[i][j];
        }
    }

    return is;
}

template <typename T>
ostream& operator<<( ostream &os, const Matrix<T> &A ) {
    int prec = 5;
    int max_length = 0;
    bool flag = false;
    double eps = 1.0e-10;
     
    for( int i = 0; i < A.rows(); ++i ) {
        for ( int j = 0; j < A.cols(); ++j ) {
            stringstream ss;
            int tmp = 0;
            ss << A[i][j];
               
            int f1 = ss.str().find(".");
            if( f1 != (int)string::npos ) {
                tmp = f1;
                flag = true;
            } else tmp = ss.str().length();
               
            tmp = ss.str().length();
            if (tmp > max_length) {
                max_length = tmp;
            }
        }
    }

    if(flag) max_length += prec+1;
    for( int i = 0; i < A.rows(); ++i ) {
        os << "[";
        for ( int j = 0; j < A.cols(); ++j ) {
            os << setw(max_length+1);
            if (flag) {
                os << setprecision(prec);
                if( abs(A[i][j]) && abs(A[i][j]) < eps )
                    os << setiosflags(ios::scientific);
                else os << setiosflags(ios::fixed);
            }
               
            os << A[i][j];
            os << resetiosflags(ios::scientific);
            os << resetiosflags(ios::fixed);
        }
        os << "]" << endl;
    }
    return os;
}

#endif
