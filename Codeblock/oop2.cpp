#include <bits/stdc++.h>
#include <sstream>
using namespace std;

using ll = long long;

class phanso
{
private:
    ll tu, mau;
public:
    phanso(ll,ll);
    void rutgon();
    ll gettuso();
    ll getmauso();
    friend ostream& operator << (ostream &out,phanso a);
    phanso operator + (phanso a);
};
ll phanso::gettuso()
{
    return this->tu;
}
ll phanso::getmauso()
{
    return this->mau;
}
ll gcd(ll a, ll b)
{
    if(b==0) return a;
    else return gcd(b,a%b);

}
ostream& operator << (ostream &out, phanso a)
{
    if (a.tu % a.mau == 0) out << a.tu << endl;
    else out << a.tu << "/" << a.mau << endl;
    return out;
}
phanso::phanso(ll a, ll b)
{
    this->tu = a;
    this->mau = b;
}
void phanso::rutgon()
{
    ll ucln = gcd(this->tu,this->mau);
    this->tu /= ucln;
    this->mau /= ucln;
}
phanso phanso::operator + (phanso a)
{
    this->tu = this->tu * a.mau + a.tu * this->mau;
    this->mau *= a.mau;
    this->rutgon();
    return *this;
}
int main()
{
    phanso x(112,145);
    phanso y(125,201);
    cout << x+y;
    return 0;
}
