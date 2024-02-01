#include <bits/stdc++.h>
#include <map>
#include <vector>
#include <sstream>
using namespace std;

class sv
{
private:
    string id, name, lop, email;
public:
    sv();
    friend istream& operator >> (istream &in, sv &a);
    friend ostream& operator << (ostream &out, sv a);
    string getlop();
};
sv::sv()
{
    id = name = lop = email = "";
}
istream& operator >> (istream &in, sv &a)
{
    cout << "Nhap id: "; in >> a.id;
    in.ignore();
    cout << "Nhap ho ten: "; getline(in,a.name);
    cout << "Nhap lop: "; in >> a.lop;
    cout << "Nhap email: "; in >> a.email;
    return in;
}
ostream& operator << (ostream &out, sv a)
{
    cout << "id: " << a.id << endl;
    cout << "ho ten: " << a.name << endl;
    cout << "lop: " << a.lop << endl;
    cout << "email: " << a.email << endl;
}
string sv::getlop()
{
    return this->lop;
}
int main()
{
    vector<sv> v;
    sv a,b;
    cin >> a >> b;
    v = {a,b};
    int nam=0; cout << "Nhap khoa can tim: " ; cin >> nam;
    string khoa = to_string(nam%100);
    for(int i = 0;i<v.size();i++)
    {
        if (v[i].getlop().substr(2,2) != khoa)
        {
            v.erase(v.begin()+i);
        }
    }
    for(auto x : v) cout << x;
}
