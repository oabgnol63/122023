#include <stdio.h>
#include <string.h>
#include <heapapi.h>
void main()
    {
        // char *c = "hello world"; -- can't be modified
        // char c[] = "hello world" ; -- can be modified
        char *c = malloc(30);
        strcpy (c,"hello world");
        char *p = c;
        *(p+1) = 'a';
        char a[] = "hello world 2";
        printf("%s\n",a);
        for(int i = 0;i<(strlen(c)+1);i++)
        {
            printf("%c",*(c+i));

        }

    }
