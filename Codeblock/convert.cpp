#include <iostream>
#include <cmath>
using namespace std;

long d2b(int n)
{
    int k = n, loop = 0;
    long p=0;
    while (k!=0)
    {
        p +=(k%2 * pow(10,loop));
        k=k/2;
        loop++;
    }
    return p;
}
long d2o(int n)
{
    int k = n, loop = 0;
    long p=0;
    while (k!=0)
    {
        p +=(k%8 * pow(10,loop));
        k=k/8;
        loop++;
    }
    return p;
}
int main()
{
    int n; cin >> n;
    long k = d2b(n);
    cout << k << endl;

}
