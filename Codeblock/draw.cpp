#include <iostream>
using namespace std;
void triagle_bot(int h,int x)
{
    for (int j = 0; j< h;j++)
{
    for (int i = 0; i<x;i++){
     if (i<j || i >= x - j)   cout << " ";
     else cout << "*";}
     cout << endl;
}
}
void triagle_top(int h,int x)
{
    for (int j = h-1; j>=0;j--)
{
    for (int i = 0; i<x;i++){
     if (i<j || i >= x - j)   cout << " ";
     else cout << "*";}
     cout << endl;
}
}
void triagle_emp(int h,int x)
{
     for (int i = 0; i<x;i++){
     cout << "*";}
     cout << endl;
    for (int j = 1; j<h;j++)
{
    for (int i = 0; i<x;i++){
     if (i!=j && i != x - j - 1)   cout << " ";
     else cout << "*";}
     cout << endl;
}
}
int main(){
cout << "Nhap chieu cao: " ;
int h; cin >> h;
int x = 2*h - 1;
triagle_emp(h,x);

}
