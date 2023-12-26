#include <stdio.h>

void main(){
    int x = 5;
    int (*p);
    p = &x;
    int **q = &p;
    int ***r = &q;
    printf("p is %d\n",p);
    printf("*p is %d\n",*p);
    printf("q is %d\n",q);
    printf("*q is %d\n",*q);
    printf("**q is %d\n",**q);
    printf("r is %d\n",r);
    printf("*r is %d\n",*r);
    printf("**r is %d\n",**r);
    printf("***r is %d\n",***r);
    printf("***r is %d\n",*(*(*r)));
    printf("--------------------------------------- \n");
    **q = *p + 2;
    printf("*q new is %d\n",*q);
    printf("p new is %d\n",p);
    printf("**q new is %d\n",**q);
    **q += 4;
    printf("x new is %d\n",x);


}
