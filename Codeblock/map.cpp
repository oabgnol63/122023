#include <iostream>
#include <map>

using namespace std;

int main()
{
    int n;
    cout << "Nhap so phan tu mang: ";
    cin >> n;
    cout << endl;
    int a[n];
    for (int i =0;i<n;i++)
    {
        cout << "Nhap phan tu thu " << i << ": ";
        cin >> a[i];
        cout << endl;
    }
    for (auto pt : a) cout << pt << " ";
    cout << endl;
    map <int,int> m;
    for (auto pt : a) m[pt]++;
    int max = 0, ind = 0;
    for (pair<int,int> item :m)
    {
            cout << item.first << " " << item.second << endl;
            if (item.second > max)
            {
                    max = item.second;
                    ind = item.first;
            }
    }
    cout << ind <<" xuat hien nhieu nhat: " << max << " lan";
}
