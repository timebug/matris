#include <iostream>
#include "../include/matris.hpp"

using namespace std;
using namespace matris;

void pM( const Matrix<double> &A ) {
    cout << A << endl;
}

int main(int argc, char *argv[])
{
    int m,n;
    while(cin>>m>>n) {
        Matrix<double> A(m,n);
        cin>>A;
        cout << rref(A) << endl;
        cout << rank(A) << endl;
    }
    return 0;
}
