// Author:   timebug
// License:  BSD

#ifndef MATRIX_HPP
#define MATRIX_HPP

template <typename T>
class Matrix
{
public:
    Matrix();
    Matrix( const Matrix<T> &A ); // A is a matrix.
    Matrix( int rows, int cols, const T *pA);
    Matrix( int rows, int cols, const T &alpha = T(0)); // alpha is a scalar.
    virtual ~Matrix();

    Matrix<T>& operator=( const Matrix<T> &A);
    Matrix<T>& operator=( const T &alpha);

    T* operator[]( int index );
    const T* operator[]( int index ) const;

    int size() const;
    int rows() const;
    int cols() const;

    Matrix<T> rows( int index ) const;
    Matrix<T> cols( int index ) const;

    T** data() const;

private:
    int size_;
    int rows_;
    int cols_;

    T* p1_;
    T** p2_;

    void init( int rows, int cols );
    void copy( const Matrix<T> &A );
}; // class Matrix

template <typename T>
void Matrix<T>::init( int rows, int cols ) {
    rows_ = rows;
    cols_ = cols;
    size_ = rows_ * cols_;
          
    p1_ = new T[size_];
    p2_ = new T*[rows_];

    assert(p1_ != NULL);
    assert(p2_ != NULL);

    p2_[0] = p1_;

    for (int i = 1; i < rows_; ++i) {
        p2_[i] = p2_[i-1] + cols;
    }
}

template <typename T>
inline void Matrix<T>::copy( const Matrix<T> &A ) {
    init( A.rows_, A.cols_ );
    for( int i = 0; i < A.rows_; ++i ) {
        for( int j = 0; j < A.cols_; ++j ) {
            p2_[i][j] = A.p2_[i][j];
        }
    }
}

template <typename T>
Matrix<T>::Matrix() :
    rows_(0), cols_(0), size_(0), p1_(0), p2_(0) {
}

template <typename T>
Matrix<T>::Matrix( const Matrix<T> &A ) {
    copy( A );
}

template <typename T>
Matrix<T>::Matrix( int rows, int cols, const T *pA ) {
    init( rows, cols );
    for (int i = 0; i < size_; ++i) {
        p1_[i] = pA[i];
    }
}

template <typename T>
Matrix<T>::Matrix( int rows, int cols, const T &alpha ) {
    init( rows, cols );
    for (int i = 0; i < size_; ++i) {
        p1_[i] = alpha;
    }
}

template <typename T>
Matrix<T>::~Matrix() {
    if (p1_ != NULL) delete []p1_;
    if (p2_ != NULL) delete []p2_;
}

template <typename T>
Matrix<T>& Matrix<T>::operator=( const Matrix<T> &A) {
    if (p1_ == A.p1_) return *this;

    if (rows_ == A.rows_ && cols_ == A.cols_) {
        copy( A );
    } else {
        this->~Matrix();
        copy( A );
    }

    return *this;
}
     
template <typename T>
Matrix<T>& Matrix<T>::operator=( const T &alpha) {
    if (alpha == 0) {
        for (int i = 0; i < size_; ++i) {
            p1_[i] = alpha;
        }
    } else {
        for (int i = 0; i < rows_; ++i) {
            for (int j = 0; j < cols_; ++j) {
                if( i == j ) p2_[i][j] = alpha;
                else p2_[i][j] = 0;
            }
        }
    }
          
    return *this;
}

template <typename T>
T* Matrix<T>::operator[]( int index ) {
    assert( index < rows_ );
    return p2_[index];
}

template <typename T>
const T* Matrix<T>::operator[]( int index ) const {
    assert( index < rows_);
    return p2_[index];
}

template <typename T>
inline int Matrix<T>::size() const {
    return size_;
}

template <typename T>
inline int Matrix<T>::rows() const {
    return rows_;
}

template <typename T>
inline int Matrix<T>::cols() const {
    return cols_;
}

template <typename T>
inline Matrix<T> Matrix<T>::rows( int index )  const {
    Matrix<T> R(1,cols_);
          
    for (int i = 0; i < cols_; ++i) {
        R[0][i] = p2_[index][i];
    }

    return R;
}

template <typename T>
inline Matrix<T> Matrix<T>::cols( int index ) const {
    Matrix<T> C(rows_,1);

    for (int i = 0; i < rows_; ++i) {
        C[i][0] = p2_[i][index];
    }

    return C;
}

template <typename T>
inline T** Matrix<T>::data() const {
    return p2_;
}

#endif
