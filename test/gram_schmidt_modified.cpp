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
        cin>>A;

        vector< Matrix<double> > V;
          
        V = gram_schmidt_modified(A);
          
        Matrix<double> Q = V.at(0);
        Matrix<double> R = V.at(1);

        cout << "Q = \n" << Q <<endl;
        cout << "R = \n" << R <<endl;
        cout << "Q*R = \n" << Q*R << endl;
        cout << "Q*tr(Q) = \n" << Q*tr(Q) << endl;
    }
    return 0;
}
