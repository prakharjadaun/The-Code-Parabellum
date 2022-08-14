#include<bits/stdc++.h>
using namespace std;

stack<long long> stack1;
stack<long long> stack2;

//to push an element into the queue
void enqueue(long long val)
{
    if(stack1.empty() && stack2.empty())
    {
        stack1.push(val);
        return;
    }

    while(!stack1.empty())
    {
        stack2.push(stack1.top());
        stack1.pop();
    }

    //as stack1 is empty 
    stack1.push(val);

    while(!stack2.empty())
    {
        stack1.push(stack2.top());
        stack2.pop();
    }
}


//to dequeue an element from the queue
void dequeue()
{
    if(stack1.empty())
        return;
    stack1.pop();
}

//to display the queue
void display()
{
    
    cout<<stack1.top()<<endl;
}



int main()
{
    int t,m,n;
    cin>>t;
    while(t--)
    {
        cin>>m;
        if(m==1)
        {
            cin>>n;
            enqueue(n);
        }
        else if(m==2)
        {
            dequeue();
        }
        else
        {
            display();
        }
    }
}

/*

STDIN   Function
-----   --------
10      q = 10 (number of queries)
1 42    1st query, enqueue 42
2       dequeue front element
1 14    enqueue 42
3       print the front element
1 28    enqueue 28
3       print the front element
1 60    enqueue 60
1 78    enqueue 78
2       dequeue front element
2       dequeue front element

Sample Output

14
14
*/


