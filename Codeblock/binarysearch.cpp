#include <iostream>
#include <stdbool.h>
#include <algorithm>

using namespace std;

bool bis (int a[],int n,int x)
{
    int m, l=0, r=n-1;
    while(l<=r){
    m = (l+r)/2;
    if(a[m]==x) { cout << "found " << x << endl; return true;}
    else if (a[m]<x) l = m+1;
    else r = m-1;
    }
    cout << "not found " << x << endl;
    return false;
}

int main(){
    int n; cin >> n;
    int a[n];
    for(int i =0;i<n;i++)
    {
        cin >> a[i];
    }
    bis(a,n,5);
    auto it = find(a,a+n,5);
    if(it == a+n) cout << "not found"; else cout << "found" << endl;

}
