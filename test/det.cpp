#include <iostream>
#include "../include/matris.hpp"

using namespace std;
using namespace matris;

int main(int argc, char *argv[])
{
    int m,n;
    while( cin >> m >> n ) {
        Matrix<double> A(m,n);
        cin >> A;
        Matrix<double> B(tr(A));
        cout << det(B) << endl;
    }
     
    return 0;
}
