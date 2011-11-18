#include <iostream>
#include <algorithm>
#include <cmath>
#include "../include/matris.hpp"

using namespace std;
using namespace matris;

void pM( Matrix<double> A ) {
    cout << A << endl;
}

int main(int argc, char *argv[])
{
    int m,n;
    while(cin>>m>>n) {
        Matrix<double> A(m,m);
        Matrix<double> b(m,n);

        cout << "Enter a " << A.rows() << "x" << A.cols() << " Matrix A :" << endl;
        cin >> A;

        cout << "Enter a " << b.rows() << "x" << b.cols() << " Matrix b:" << endl;
        cin >> b;

        Matrix<double> x = guassian_elimination(A,b);
        cout << "x = \n" << x << endl;
    }

    return 0;
}
