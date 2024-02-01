#include <bits/stdc++.h>
using namespace std;

class xe
{
private:
    string bienso;
public:
    xe()
    {
        cout << "Doi tuong xe duoc tao";
    }
};

class xemay : public xe
{
private:
    string loaixe;
public:
    xemay()
    {
        cout << "Doi tuong xe may duoc tao";
    }
};
class xemoto : public xemay
{
private:
    string loaixe;
public:
    xemoto()
    {
        cout << "Doi tuong xe mo to dc tao";
    }
};
int main()
{
    xemoto a;
}
