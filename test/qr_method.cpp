#include <iostream>
#include "../include/matris.hpp"

using namespace std;
using namespace matris;

int main(int argc, char *argv[])
{
    int m,n;
    while(cin>>m>>n) {
        Matrix<double> A(m,n);
        double eps = 1.0e-10;
        cin>>A;
        cout << qr_method(A,eps) << endl;
    }
    return 0;
}
