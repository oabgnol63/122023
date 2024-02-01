#include <iostream>
#include <math.h>
using namespace std;
int checkint(float n)
{
int res=n/1;
if(n<=0 || n>=0 && res*1==n)
{
return 1;
}
else
{
return 0;
}}
int main()
{
    for (int i = 3;i<2500;i++)
    {
        for(int j = i+1;j<2500;j++)
        {
            float k = sqrt(i*i+j*j);
            if(checkint(k)==1 && (i+j+k) < 5000) {cout << i <<" " << j << " " << k << endl; break;}

        }
    }
}
