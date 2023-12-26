#include <iostream>
#include <set>

using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;
    int a[n];
    multiset<int> ms;
    for (int &x : a) cin >> x;
    for (int i= 0;i<k;i++) ms.insert(a[i]);
    for (auto x : ms) cout << x << " ";
    cout << endl;
    for (int i =k;i<n+1;i++)
    {
        cout << *ms.rbegin() << " ";
        ms.insert(a[i]);
        ms.erase((a[i-k]));
    }

}
