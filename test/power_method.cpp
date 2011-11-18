#include <iostream>
#include "../include/matris.hpp"

using namespace std;
using namespace matris;

int main(int argc, char *argv[])
{
    int m,n;
    while(cin>>m>>n) {
        Matrix<double> A(m,n);
        cin>>A;
        vector< Matrix<double> > V;
        double eps = 1.0e-10;
          
        V = power_method(A,eps);

        Matrix<double> la = V.at(0);
        Matrix<double> x = V.at(1);

        double lambda = la[0][0];

        cout << "lambda = " << lambda << endl;
        cout << "x = \n" << x << endl;
    }
    return 0;
}
