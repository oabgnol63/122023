#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class sinhvien
{
private:
    string id, ten, ngaysinh;
    double gpa;
    static int dem; // chung cho moi doi tuong
public:
    sinhvien();
    sinhvien(string,string,string,double);
    string getid();
    void setid(string id);
    void nhap();
    void in();
    friend void chuanhoa(sinhvien&);
    friend istream& operator >> (istream &in, sinhvien &a);
    friend ostream& operator << (ostream &out, sinhvien a);
    bool operator < (sinhvien a);
};
int sinhvien::dem = 0;
sinhvien::sinhvien()
{
    cout << "Constructor mac dinh duoc tao \n";
    id = ten = ngaysinh = "";
    gpa = 0;
}
sinhvien::sinhvien(string id,string ten,string ngaysinh,double gpa)
{
    cout << "Ham khoi tao co tham so \n";
    this->id = id;
    this->ten = ten;
    this->ngaysinh = ngaysinh;
    this->gpa = gpa;
}
string sinhvien::getid()
{
    return this->id;
}
void sinhvien::setid(string id)
{
    this->id = id;
}
void sinhvien::nhap()
{
    dem++;
    this->id = "SV" + string(3-to_string(dem).length(),'0') + to_string(dem);
    cout << "Nhap ten SV: " ; getline(cin,this->ten);
    cout << "Nhap ngay sinh: "; cin >> this->ngaysinh;
    cout << "Nhap diem: "; cin >> this->gpa;
    cin.ignore();
}
void sinhvien::in()
{
    cout << "MSSV: " << id << endl;
    cout << "Ho ten: " << ten << endl;
    cout << "Ngay sinh: " << ngaysinh << endl;
    cout << "Diem trung binh: " << gpa << endl;
}
void chuanhoa(sinhvien &a)
{
    string token, temp = "";
    stringstream ss(a.ten);
    while(ss >> token)
    {
        temp += toupper(token[0]);
        for(int i = 1;i<token.length();i++)
            temp += tolower(token[i]);
        temp += ' ';
    }
    temp.erase(temp.length()-1);
    a.ten = temp;
}

istream& operator >> (istream &in, sinhvien &a)
{
    cout << "Nhap id:"; in >> a.id;
    cout << "Nhap ten: "; in.ignore(); getline(in,a.ten);
    cout << "Nhap ngay sinh: "; in >> a.ngaysinh;
    cout << "Nhap diem: "; in >> a.gpa;
    return in;
}
ostream& operator << (ostream &out,sinhvien a)
{
    out << "MSSV: " << a.id << endl;
    out << "Ho ten: " << a.ten << endl;
    out << "Ngay sinh: " << a.ngaysinh << endl;
    out << "Diem trung binh: " << a.gpa << endl;
    return out;
}
bool sinhvien::operator < (sinhvien a)
{
    return this->gpa < a.gpa;
}
int main()
{
    vector<sinhvien> v;
    sinhvien tmp;
    while (cin >> tmp)
    {
        v.push_back(tmp);

    }
    cout << "\n------------------------------------------------\n";
    for(auto x : v) cout << x << endl;
}
