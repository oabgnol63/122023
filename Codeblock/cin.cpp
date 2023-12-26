#include <iostream>
#include <vector>
using namespace std;

void chuanhoa(string &a)
{
    if(a.find('"') != string::npos)
    {
        a = a.substr(a.find_first_of('"')+1,a.find_last_of('"')-1);
    }
}

int main()
{
    string a = "universe";
    chuanhoa(a);
    cout << a;
}
