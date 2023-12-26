#include <iostream>
using namespace std;

int partition(int a[], int l,int r)
{
    int pv = a[r];
    int i = l -1 ;
    for (int j = l;j<r;j++)
    {
        if(a[j]<=pv)
        {
            ++i;
            swap(a[i],a[j]);
        }
    }
    ++i;
    swap(a[i],a[r]);
    return i;
}
int pt(int a[],int l,int r)
{
    int i = l - 1;
    int pv  = a[r];
    for ( int j = l;j<r;j++)
    {
        if(a[j]<=pv)
        {
            i++;
            swap(a[i],a[j]);
        }
    }
    i++;
    swap(a[i],a[r]);
    return i;
}
int partition2(int a[], int l, int r)
{
    int pv = a[l];
    int i = l -1 ;
    int j = r + 1;
    while(1)
    {
        do
        {
            ++i;
        } while (a[i] < pv);
        do
        {
            --j;
        } while (a[j] > pv);
        if (i<j) swap(a[i],a[j]);
        else return j;
    }
}
void quicksort(int a[],int l,int r)
{
    if(l>=r) return;
    int p = pt(a,l,r);
    quicksort(a,l,p-1);
    quicksort(a,p+1,r);
}
void quicksort2(int a[],int l, int r)
{
    if(l>=r) return;
    int p = partition2(a,l,r);
    quicksort2(a,l,p);
    quicksort2(a,p+1,r);
}

int main()
{
    int n; cin >> n;
    int a[n];
    srand(time(NULL));
    for (int i =0;i<n;i++)
        a[i] = rand() % 10;
    quicksort(a,0,n-1);
    for (int i = 0; i<n;i++) cout << a[i] << " ";
    return 0;
}
