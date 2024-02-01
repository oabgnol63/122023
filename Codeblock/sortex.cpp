#include <iostream>
#include <algorithm>
#include <string.h>
#include <sstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <stack>
using namespace std;

struct node
{
    int data;
    struct node *pnext;
};
typedef struct node node;

node *newnode(int x)
{
    node *nn = new node;
    nn -> data = x;
    nn -> pnext = NULL;
    return nn;
}
int size(node *head)
{
    int cnt = 0;
    while(head->pnext != NULL)
    {
        cnt++;
        head = head->pnext;
    }
    return cnt + 1;
}
void duyet(node *head)
{
    while(head != NULL)
    {
        cout << head->data << " ";
        head = head->pnext;
    }
    cout << endl;
}

void push_front(node **head,int x)
{
    node *nn = newnode(x);
    nn->pnext = *head;
    *head = nn;
}

void push_back(node **head,int x)
{
    node *temp = NULL;
    node *nn = newnode(x);
    temp = *head;
    if(*head == NULL)
    {
        *head = nn;
        return;
    }
    while(temp->pnext != NULL)
        temp = temp->pnext;
    temp->pnext = nn;
}
void reverse(node **head)
{
    node *temp = *head;
    stack<node> s;
    while(temp->pnext != NULL)
    {
        s.push(*temp);
        temp = temp->pnext;
    }
    s.push(*temp);
    //cout << "Size of stack: " << s.size() << endl;
    while(!s.empty())
    {
        cout << s.top().data << " ";
        s.pop();
    }
    cout << endl;

}
void insert(node **head,int x, int k)
{
    int n = size(*head);
    if(k<1 || k > n) return;
    if(k ==1 )
    {
        push_front(head,x);
        return;
    }
    node *temp = *head;
    for(int i =0;i<k-2;i++)
    {
        temp = temp->pnext;
    }
    node *nn = newnode(x);
    nn->pnext = temp->pnext;
    temp->pnext = nn;

}
int main()
{
    node *head = NULL;
    int n= 0, x= 0;
    while(1)
    {
        cout << "-----------------MENU-------------------"  << endl;
        cout << "1/ Them node vao dau DSLK \n";
        cout << "2/ Them node vao giua DSLK \n";
        cout << "3/ Them node vao cuoi DSLK \n";
        cout << "4/ Dao nguoc DSLK \n";
        cout << "5/ In DSLK \n";
        cout << "0/ Thoat \n";
        cout << "----------------------------------------"  << endl;
        cin >> n;
        switch (n)
        {
        case 1:
            {
                system("cls");
                cout << "Nhap gia tri node:"; cin >> x;
                push_front(&head,x);
                break;
            }
        case 3:
            {
                system("cls");
                cout << "Nhap gia tri node:"; cin >> x;
                push_back(&head,x);
                break;
            }
        case 2:
            {
                system("cls");
                cout << "Nhap gia tri node:"; cin >> x;
                cout << "Nhap vi tri: ";
                int k = 0; cin >> k;
                insert(&head,x,k);
                break;
            }
        case 4:
            {
                system("cls");
                reverse(&head);
                break;
            }
        case 5:
            {
                system("cls");
                duyet(head);
                break;
            }
        case 0:
            {
                return 0;
            }
        default:
            {
                return 0;
            }
        }
    }

    return 0;
}
