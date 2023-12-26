#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector <int> k;
    for (int i = 0; i<10;i++) k.push_back(i);
    for (auto j = k.begin();j != k.end();j++)
    {
        cout << *j << endl;
    }
    for (int a = 0; a < k.size();a++)
    {
        cout << k[a] << " " ;
    }
    cout << endl;
    for(int y : k) cout << y << " ";
    cout << endl;
    cout << "Nhap so phan tu: ";
    int n; cin >> n;
    vector <string> l(n,"dmm");
    l.push_back("conchonay");
    for (string a : l) cout << a << "\t";
    cout << endl;
    l.pop_back ();
    for (string a : l) cout << a << "\t";


}
