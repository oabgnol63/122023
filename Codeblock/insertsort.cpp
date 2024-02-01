#include <iostream>
using namespace std;

void insertsort(int a[], int n)
{
    for (int i = 1;i<n;i++)
    {
        int pos = i - 1;
        int x = a[i];
        while(pos >=0 && x < a[pos])
        {
            a[pos+1]=a[pos];
            pos--;
        }
        a[pos+1] = x;
    }
}
int main(){
int n; cin >> n;
int a[n];
for (int i= 0;i<n;i++) cin >> a[i];
insertsort(a,n);
for (int x : a) cout << x << " ";
return 0;
}
