#include <iostream>
#include "../include/matris.hpp"

using namespace std;
using namespace matris;

int main(int argc, char *argv[])
{
    int n,m;
    while(cin>>n>>m) {
        Matrix<double> A(n,m);
        cin>>A;
        cout << cond(A,"inf") << endl;
        cout << A << endl;
    }
    return 0;
}
