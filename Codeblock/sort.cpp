#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdbool.h>
using namespace std;
bool cmp(string a,string b)
{
    if(a.length() != b.length()) return a.length() < b.length(); // phan tu dung truoc ngan hon phan tu dung sau
    return a < b; // thu tu tu dien
}
using namespace std;

int main(){
int n; cin >> n;
//int a[n];
string a[n];
for(int i=0;i<n;i++) cin >> a[i];
sort(a,a+n,cmp);
for(auto x : a) cout << x <<" ";


}
