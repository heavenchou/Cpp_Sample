#include <iostream>
using namespace std;

template <class T>
T GetMax (T a, T b)
{
    T result;
    result = (a>b)? a : b;
    return (result);
}

template <class T, class V>
T GetMax2 (T a, V b)
{
    return (a>b)? a : b;
}

int main ()
{
    int i=5, j=8, k;
    long l=10, m=5, n;
    float o=7.7, p=9.9, q;
    k=GetMax<int>(i,j);
    n=GetMax<long>(l,m);
    cout << k << endl;
    cout << n << endl;

    k=GetMax2(i,j);
    n=GetMax2(i,o);
    q=GetMax2(o,p);
    cout << k << endl;
    cout << n << endl;
    cout << q << endl;
    return 0;
}
