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
        cout<<"norm(1)="<<norm(A,"1")<<endl;
        cout<<"norm(2)="<<norm(A,"2")<<endl;
        cout<<"norm(inf)="<<norm(A,"inf")<<endl;

        cout<<"norm(1)="<<norm(inv(A),"1")<<endl;
        cout<<"norm(2)="<<norm(inv(A),"2")<<endl;
        cout<<"norm(inf)="<<norm(inv(A),"inf")<<endl;
    }

    return 0;
}
