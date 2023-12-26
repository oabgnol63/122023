#include <stdio.h>

void doubleArray(int *a,int size)
    {
        for(int i=0;i<size;i++)
        a[i] = 2 *(a[i]);
    }

void main()
    {
        int a[] = {1,2,3,4,5};
        int size = sizeof(a)/4;
        doubleArray(a,size);
        for (int i =0;i<size;i++)
            {
                printf("%d\t",a[i]);
            }
    }
