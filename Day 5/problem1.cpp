#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};


void InorderTraversal(struct Node *head)
{
    if(head==NULL)
    {
        return;
    }

    InorderTraversal(head->left);
    cout<<head->data<<endl;
    InorderTraversal(head->right);
}

/*
      1
      \
       2
        \
         5
        /  \
       3    6
        \
         4  

Sample Output :
1 2 3 4 5 6 
*/