#include <iostream>
#include "../include/matris.hpp"

using namespace std;
using namespace matris;

void pM( const Matrix<double> &A ) {
    cout << "\n" << A << endl;
}

int main(int argc, char *argv[])
{
    int m,n;
    while(cin >> m >> n) {
        Matrix<double> A(m,n);
        cin >> A;
        cout << inv(A) << endl;
    }
    return 0;
}
