#include <iostream>
#include <vector>
#include "../include/matris.hpp"

using namespace matris;
using namespace std;

void pM( const Matrix<double> &A ) {
    cout << A << endl;
}

int main(int argc, char *argv[])
{
    int m,n;
    while( cin >> m >> n ) {
        vector< Matrix<double> > V;
        Matrix<double> A(m,n);

        cin >> A;

        V = lu(A);

        if(!V.empty()) {
            Matrix<double> L = V.at(0);
            Matrix<double> U = V.at(1);
            Matrix<double> P = V.at(2);

            cout << "L =\n" << L << endl;
            cout << "U =\n" << U << endl;
            cout << "P =\n" << P << endl;
        } else {
            cout << "error" << endl;
        }
    }

    return 0;
}
