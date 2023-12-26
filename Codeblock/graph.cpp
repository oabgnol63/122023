#include <iostream>
#include <set>
using namespace std;
int main()
{
    int a[5] = {3,2,5,4,3};
    set<int> s;
    for(int i = 0;i<5;i++)
        s.insert(a[i]);
    cout << s.size();
}
