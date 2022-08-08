#include<bits/stdc++.h>
#include<vector>
using namespace std;
int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3) 
{
    int s1=0,s2=0,s3=0;
    s1 = accumulate(h1.begin(),h1.end(),0);
    s2 = accumulate(h2.begin(),h2.end(),0);
    s3 = accumulate(h3.begin(),h3.end(),0);
    
    if(s1==0 || s2==0 || s3==0)
    {
        return 0;
    }
    
    bool flag = true;
    while(flag)
    {
        if(s1==s2 && s1<s3)
        {  
            s3 = s3 - h3[0];
            h3.erase(h3.begin());
        }
        else if(s1==s3 && s1<s2)
        {      
            s2 = s2 -h2[0];
            h2.erase(h2.begin());
        }
        else if(s2==s3 && s2<s1)
        {
            
            s1 = s1 - h1[0];
            h1.erase(h1.begin());
        }
        else if(s1==s2 && s1==s3)
        {
            flag = false;
            break;
        }
        else if(s1<s2 && s1<s3)
        {
            s2 = s2 - h2[0];
            s3 = s3 - h3[0];
            h2.erase(h2.begin());
            h3.erase(h3.begin());
        }
        else if(s2<s1 && s2<s3)
        {
            s1 = s1 - h1[0];
            s3 = s3 - h3[0];
            h1.erase(h1.begin());
            h3.erase(h3.begin());
        }
        else
        {
            s1 = s1 - h1[0];
            s2 = s2 - h2[0];
            h1.erase(h1.begin());
            h2.erase(h2.begin());
        }
    }
    return s1;
}

int main()
{
    int n1,n2,n3;
    cin>>n1>>n2>>n3;
    int val;
    vector<int> h1(n1),h2(n2),h3(n3);
    for(int i=0;i<n1;i++)
    {
        cin>>val;
        h1.push_back(val);
    }

    for(int i=0;i<n2;i++)
    {
        cin>>val;
        h2.push_back(val);
    }

    for(int i=0;i<n3;i++)
    {
        cin>>val;
        h3.push_back(val);
    }

    cout<<equalStacks(h1,h2,h3)<<endl;
    return 0;
}

/*

STDIN       Function
-----       --------
5 3 4       h1[] size n1 = 5, h2[] size n2 = 3, h3[] size n3 = 4  
3 2 1 1 1   h1 = [3, 2, 1, 1, 1]
4 3 2       h2 = [4, 3, 2]
1 1 4 1     h3 = [1, 1, 4, 1]

STDOUT 
------
5
*/