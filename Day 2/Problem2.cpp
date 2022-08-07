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

void displayEvenOdd(struct Node *head)
{
    struct Node *temp=head;
    int num=1;
    while(temp)
    {
        if(num%2!=0)
        cout<<temp->data<<endl;

        temp = temp->next;
        num++;
    }

    num = 1;

    temp = head;
    while(temp)
    {
        if(num%2==0)
        cout<<temp->data<<endl;
        
        temp = temp->next;
        num++;
    }
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

    displayEvenOdd(head);

    return 0;
}