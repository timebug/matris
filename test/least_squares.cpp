#include <iostream>
#include <vector>
#include "../include/matris.hpp"

using namespace std;
using namespace matris;

int main(int argc, char *argv[])
{
    int m,n;
    while(cin>>m>>n) {
        Matrix<double> A(m,n);
        Matrix<double> b(m,1);
          
        cout << "Enter a " << A.rows() << "x" << A.cols() << " Matrix A :" << endl;
        cin >> A;

        cout << "Enter a " << b.rows() << "x" << b.cols() << " Matrix b:" << endl;
        cin >> b;

        Matrix<double> x = least_squares(A,b);

        cout << "x = \n" << x << endl;
    }
    return 0;
}
