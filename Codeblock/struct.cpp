#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
struct sinhvien
{
    string masv, hoten, lop, ngaysinh;
    double gpa;
    void nhap()
    {
        cout << "Nhap ma SV: "; cin >> masv;
        cout << "Nhap ten SV: "; cin.ignore(); getline(cin,hoten);
        cout << "Nhap lop SV: "; cin >> lop;
        cout << "Nhap ngay sinh: "; cin >> ngaysinh;
        cout << "Nhap GPA: "; cin >> gpa;
    };
    void in()
    {
        cout << "-----------------------------------------------" << endl;
        cout << "Ma SV: " << masv << endl;
        cout << "Ten SV: " << hoten << endl;
        cout << "Lop: " << lop << endl;
        cout << "Ngay sinh: " << ngaysinh << endl;
        cout << "Diem trung binh: " << gpa << endl;
        cout << "-----------------------------------------------" << endl;
    };
};
void find(sinhvien sv[],int n)
{
    string token;
    bool found = false;
    cout << "Nhap ma SV can tim: "; cin >> token;
    for(int i = 0; i<n; i++)
    {
        if(sv[i].masv.find(token) != string::npos)
        {
            sv[i].in();
            found = true;
        }
    }
    if(found == false) cout << "Khong tim thay sinh vien \n";
}
void highest_gpa(sinhvien sv[],int n)
{
    double temp = 0;
    for(int i = 0;i<n;i++)
    {
        if(sv[i].gpa>temp) temp = sv[i].gpa;
    }
    for(int i = 0;i<n;i++)
    {
        if(sv[i].gpa == temp) sv[i].in();
    }
}
bool gpa_cmp(sinhvien a, sinhvien b)
    {
        return a.gpa > b.gpa;
    }
vector<string> chuanhoaten(string name)
{
    vector<string> v;
    stringstream ss(name);
    string temp;
    while(ss >> temp)
        v.push_back(temp);
    return v;
}
bool name_cmp(sinhvien a, sinhvien b)
{
    vector<string> v1 = chuanhoaten(a.hoten), v2 = chuanhoaten(b.hoten);
    if(v1.back() != v2.back()) return v1.back() < v2.back();
    int len1 = v1.size(), len2 = v2.size();
    if(v1[len1 -2] != v2[len2 -2]) return v1[len1 -2] < v2[len2 -2];
    if(v1[0] != v2[0]) return v1[0] < v2[0];
    return len1 < len2;
}
bool class_cmp(sinhvien a, sinhvien b)
{
    if(a.lop != b.lop) return a.lop < b.lop;
    vector<string> v1 = chuanhoaten(a.hoten), v2 = chuanhoaten(b.hoten);
    if(v1.back() != v2.back()) return v1.back() < v2.back();
    int len1 = v1.size(), len2 = v2.size();
    if(v1[len1 -2] != v2[len2 -2]) return v1[len1 -2] < v2[len2 -2];
    if(v1[0] != v2[0]) return v1[0] < v2[0];
    return len1 < len2;
}

void gpa_filter(sinhvien sv[],int n)
{
    vector<sinhvien> v;
    double t_gpa;
    cout << "Nhap min GPA: "; cin >> t_gpa;
    for(int i = 0;i<n;i++)
    {
        if(sv[i].gpa > t_gpa) v.push_back(sv[i]);
    }
    sort(v.begin(),v.end(),gpa_cmp);
    for(auto x : v) x.in();
}
void alphabet_sort(sinhvien sv[],int n)
{
    sort(sv,sv+n,name_cmp);
}
void class_sort(sinhvien sv[],int n)
{
    sort(sv,sv+n,class_cmp);
}
bool date_cmp(sinhvien a,sinhvien b)
{
    int d1 = (a.ngaysinh[0] - '0') * 10 + (a.ngaysinh[1] - '0'), m1 = (a.ngaysinh[3] - '0') * 10 + (a.ngaysinh[4] - '0'), y1 = stoi(a.ngaysinh.substr(6));
    int d2 = (b.ngaysinh[0] - '0') * 10 + (b.ngaysinh[1] - '0'), m2 = (b.ngaysinh[3] - '0') * 10 + (b.ngaysinh[4] - '0'), y2 = stoi(b.ngaysinh.substr(6));
    if(y1 != y2) return y1 < y2;
    if(m1 != m2) return m1 < m2;
    return d1 < d2;
}
void date_sort(sinhvien sv[],int n)
{
    sort(sv,sv+n,date_cmp);
}
int main()
{
    sinhvien sv[1000];
    int n = 0;
    int choice = 0;
    while(1)
    {
        cout << "-----------------------MENU--------------------" << endl;
        cout << "1/ Nhap danh sach sinh vien" << endl;
        cout << "2/ In danh sach sinh vien" << endl;
        cout << "3/ Tim kiem sinh vien theo ma SV" << endl;
        cout << "4/ SV co gpa cao nhat" << endl;
        cout << "5/ Loc SV theo GPA" << endl;
        cout << "6/ Sap xep sinh vien theo ten" << endl;
        cout << "7/ Sap xep sinh vien theo lop" << endl;
        cout << "8/ Sap xep sinh vien theo ngay sinh" << endl;
        cout << "0/ Thoat" << endl;
        cout << "-----------------------------------------------" << endl;
        cin >> choice;
        switch(choice)
        {
        case 1:
            sv[n].nhap();
            n++;
            break;
        case 2:
            for(int i = 0; i<n;i++)
                sv[i].in();
            break;
        case 3:
            if(n==0)
            {
                cout << "Danh sach sinh vien trong \n";
                break;
            }
            else
            find(sv,n);
        case 4:
            if(n==0)
            {
                cout << "Danh sach sinh vien trong \n";
                break;
            }
            else
            highest_gpa(sv,n);
            break;
        case 5:
            if(n==0)
            {
                cout << "Danh sach sinh vien trong \n";
                break;
            }
            else
            gpa_filter(sv,n);
            break;
        case 6:
            if(n==0)
            {
                cout << "Danh sach sinh vien trong \n";
                break;
            }
            else
            alphabet_sort(sv,n);
            break;
        case 7:
            if(n==0)
            {
                cout << "Danh sach sinh vien trong \n";
                break;
            }
            else
            class_sort(sv,n);
            break;
        case 8:
            if(n==0)
            {
                cout << "Danh sach sinh vien trong \n";
                break;
            }
            else
            date_sort(sv,n);
            break;
        default:
            return 0;
            break;
        }
    }
}
