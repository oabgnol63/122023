#include <stdio.h>

void main()
    {
        int x,y, k=0;
        printf("Nhap so hang: ");
        scanf("%d",&x);
        printf("Nhap so cot: ");
        scanf("%d",&y);
        int a[x][y], (*p)[x] = a;
        for(int i=0;i<x;i++)
        {
            for(int j = 0;j<y;j++)
                {
                    printf("Nhap phan tu thu %d: ",k);
                    scanf("%d",&a[i][j]);
                    k++;
                }
        }

        for(int i=0;i<x;i++)
        {
            for(int j = 0;j<y;j++)
                {
                    printf("%d\t",*(*(p+i)+j));
                }
        }
        printf("\n");
                for(int i=0;i<x;i++)
        {
            for(int j = 0;j<y;j++)
                {
                    printf("%d\t",*(a[i]+j));
                }
        }
    }


