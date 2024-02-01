#include <bits/stdc++.h>
using namespace std;

class person
{
private:
    string ten;
    uint16_t tuoi;
public:
    person(string ten,uint16_t tuoi)
    {
        cout << "person created \n";
        this->ten = ten;
        this->tuoi = tuoi;
    }
    string getname()
    {
        return ten;
    }
    uint16_t gettuoi()
    {
        return tuoi;
    }
    void in()
    {
        cout << ten;
    }
};

class student : public person
{
private:
    uint16_t lop;
public:
    student(string ten,uint16_t tuoi,uint16_t lop) : person(ten,tuoi)
    {
        cout << "student created \n";
        this->lop = lop;
    }
    uint16_t getlop()
    {
        return lop;
    }
    void in()
    {
        cout << lop;
    }
};

int main()
{
    student st("bao",15,8);
    st.person::in();
}
