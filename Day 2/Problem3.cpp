#include<bits/stdc++.h>
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

int lengthOfList(struct Node* start)
{
    if(start==NULL)
    return 0;

    struct Node *temp = start;
    int counter=0;
    while(temp)
    {
        temp=temp->next;
        counter++;
    }
    return counter;
}

struct Node *reverseNodeInKGroup(struct Node *head,int k)
{
    struct Node *temp = NULL, *temp2= NULL,*curr = head,*var=NULL;
    
    int num=0;
    while (curr && num<k) 
    {
        temp2 = curr->next;
        curr->next= temp;
        temp = curr;
        curr = temp2;
        num++;
    }

    if(temp2)
    {
        if(lengthOfList(temp2)>=k)
        {
            head->next = reverseNodeInKGroup(temp2,k);
        }
        else
        {
            var = temp2;
            while(var)
            {
                head->next = var;
                head = head->next;
                var = var->next;
            }
        }
    }
    return temp;
}
int main()
{
    int n,temp,k;
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

    cin>>k;
    if(lengthOfList(head)>=k)
    head = reverseNodeInKGroup(head,k);
    display(head);

    return 0;
}

/*
Sample Input:
5
1 2 3 4 5
2

Expected Output:
2
1
4
3
5
*/