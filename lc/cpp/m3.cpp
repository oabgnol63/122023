#include <iostream>
#include <stack>
struct ListNode {
    int val;
    ListNode *pnext;
    ListNode() : val(0), pnext(nullptr) {}
    ListNode(int x) : val(x), pnext(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), pnext(next) {}
};
typedef struct ListNode node;

int count(node *head) {
    int i = 0;
    while(head->pnext != NULL) {
        i++;
        head = head->pnext;
    }
    return i;
}

void scan(node *head) {
    while(head != NULL)
    {
        std::cout << head->val << " ";
        head = head->pnext;
    }
    std::cout << std::endl;
}

void push_front(node **head, int val) {
    node *nn = new node(val);
    if(*head == NULL) {
        *head = nn;
    } else {
        nn->pnext = *head;
        *head = nn;
    }
}

void push_back(node **head, int val) {
    node *nn = new node(val);
    node *temp = *head;
    if(*head == NULL) {
        *head = nn;
        return;
    }
    while(temp->pnext != NULL) {
        temp = temp->pnext;
    }
    temp->pnext = nn;
}

void push_index(node **head, int val, int index) {
    if(index < 1 || index > count(*head)) {
        return;
    }
    int i = 0;
    node *nn = new node(val);
    node *temp = *head;
    while(i < index - 1 && temp->pnext != NULL) {
        i++;
        temp = temp->pnext;
    }
    nn->pnext = temp->pnext;
    temp->pnext = nn;
}

void reverse(node *head) {
    std::stack<node*> s;
    //node *temp = *head;
    while(head->pnext != NULL) {
        s.push(head);
        head = head->pnext;
    }
    s.push(head);
    while(!s.empty()) {
        std::cout << s.top()->val << " ";
        s.pop();
    }
    std::cout << "\n";
}

int node_to_int(node *head) {
    int sum = 0, index = 1;
    while(head->pnext != NULL) {
        sum += head->val * index;
        head = head->pnext;
        index *= 10;
    }
    sum += head->val * index;
    return sum;
}

node* node_from_array(int *arr,int k) {
    node *nn = NULL;
    for(int i = 0; i < k; i++) {
        push_back(&nn,*(arr+i));
    }
    return nn;
} 

node* node_from_int(int val) {
    node *nn = NULL;
    int cnt = 0;
    while(val / 10 != 0) {
        push_front(&nn,val%10);
    }
    return nn;
}

int main()
{
    node *head = NULL;
    int n= 0, x= 0;
    while(1)
    {
        std::cout << "-----------------MENU-------------------"  << std::endl;
        std::cout << "1/ Them node vao dau DSLK \n";
        std::cout << "2/ Them node vao giua DSLK \n";
        std::cout << "3/ Them node vao cuoi DSLK \n";
        std::cout << "4/ Dao nguoc DSLK \n";
        std::cout << "5/ In DSLK \n";
        std::cout << "6/ Link list to value \n";
        std::cout << "7/ Link list from array \n";
        std::cout << "7/ Link list from int \n";
        std::cout << "0/ Thoat \n";
        std::cout << "----------------------------------------"  << std::endl;
        std::cin >> n;
        switch (n)
        {
        case 1:
            {
                system("cls");
                std::cout << "Nhap gia tri node:"; std::cin >> x;
                push_front(&head,x);
                break;
            }
        case 2:
            {
                system("cls");
                std::cout << "Nhap gia tri node:"; std::cin >> x;
                std::cout << "Nhap vi tri: ";
                int k = 0; std::cin >> k;
                push_index(&head,x,k);
                break;
            }
        case 3:
            {
                system("cls");
                std::cout << "Nhap gia tri node:"; std::cin >> x;
                push_back(&head,x);
                break;
            }
        case 4:
            {
                system("cls");
                reverse(head);
                break;
            }
        case 5:
            {
                system("cls");
                scan(head);
                break;
            }
        case 6:
            {
                system("cls");
                std::cout << node_to_int(head) << "\n";
                break;
            }
        case 7:
            {
                system("cls");
                node *nn = new node();
                int a[5] = {1,2,3,4,5};
                nn = node_from_array(a,5);
                scan(nn);
                delete nn; nn = NULL;
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