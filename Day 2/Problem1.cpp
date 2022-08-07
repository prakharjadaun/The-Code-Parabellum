#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node 
{
    int data;
    struct Node* next;

    Node(int x)
    {
        data=x;
        next=NULL;
    }
};

void display(struct Node *head)
{
    struct Node *temp=head;
    while(temp)
    {
        cout<<temp->data<<endl;
        temp = temp->next;
    }
}
struct Node *reverse(struct Node *head)
{
    struct Node *temp = NULL, *temp2= NULL,*curr = head;

    while (curr) 
    {
        temp2 = curr->next;
        curr->next= temp;
        temp = curr;
        curr = temp2;
    }
    head = temp;
    return head;
}
int main()
{
    int n,temp;
    cin>>n;
    struct Node *head=NULL,*tail=NULL;

    for(int i=0;i<n;i++)
    {
        cin>>temp;
        if(head==NULL)
        {
            head = new Node(temp);
            tail = head;
        }
        else
        {
            tail->next = new Node(temp);
            tail = tail->next;
        }
    }

    head = reverse(head);

    display(head);
    return 0;
}

/*
Sample Input:
6
1 2 3 4 5 6

Sample Output:
6
5
4
3
2
1
*/