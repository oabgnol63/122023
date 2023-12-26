#include <iostream>
#include <set>

using namespace std;
// set ko co index
int main(){
set <int> k;
for (int i = 9; i>=0;i--) k.insert(i);
for (auto z :k) cout << z << " ";
cout << endl;
for (auto j = k.begin(); j != k.end();j++) cout << *j << " ";
cout << endl;
if (k.find(0) != k.end()) cout << "found 0" << endl;
auto q = k.count(3); cout << q;
for (auto i = k.begin(); i != k.end();i++)
    if ((*i) > 5) k.erase(i);
cout << endl;
for (auto z : k) cout << z << " ";
cout << endl;
for (set<int>::iterator z = k.begin();z != k.end(); ++z) cout << *z << " ";
cout << endl;
cout << "Nhap so tu: ";
int n;  cin >> n;
string ss; set<string> s;
cin.ignore();
for (int t = 0; t<n;t++)
    {
        cout << "Nhap tu thu " << t << ":";
        getline(cin,ss);
        s.insert(ss);
        cout << endl;
    }
for (auto r : s) cout << r << " ";
cout << endl;
multiset<int> ms;
for (int i = 100;i<111;i++) ms.insert(i);
ms.insert(101);
for (auto k : ms) cout << k << " ";
cout << endl;
auto it = ms.find(101);
ms.erase(it); // chi xoa 1 phan tu
for (auto k : ms) cout << k << " ";
}


