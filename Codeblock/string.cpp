#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int main(){
char *s;
s = new char[20];
gets(s);
cout<<s<<endl;
int k = strlen(s);
for (int i =0;i<k;i++) cout << *(s+i);

char *name[5];
for (int j=0;j<5;j++)
{
    name[j] = new char[20];
    cout<<"Ten thu "<<j<<":"; gets(name[j]);
}
for (int k=0;k<5;k++) cout<<name[k]<<" ";
return 0;
}
