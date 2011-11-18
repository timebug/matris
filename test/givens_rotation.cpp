#include <iostream>
#include <vector>
#include <cmath>
#include "../include/matris.hpp"

using namespace std;
using namespace matris;

void pM( const Matrix<double> &A ) {
    cout << endl;
    cout << A << endl;
}

int main(int argc, char *argv[])
{
    int m,n;
    while(cin>>m>>n) {
        Matrix<double> A(m,n);
        cin>>A;

        vector< Matrix<double> > V;

        V = givens_rotation(A);

        Matrix<double> Q = V.at(0);
        Matrix<double> R = V.at(1);

        cout << "Q = \n" << Q << endl;
        cout << "R = \n" << R << endl;
        cout << "Q*R = \n" << Q*R << endl;
        cout << "Q*tr(Q)= \n" << Q*tr(Q) << endl;
    }
    return 0;
}
