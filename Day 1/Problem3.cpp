#include<bits/stdc++.h>
using namespace std;

int Xor(int i,int j)
{
    return abs(i-j);
}

int main()
{
    string str1,str2;
    cin>>str1;
    cin>>str2;

    int v1[14],v2[14];
    int m=0,n=0;
    for(int i=0;i<str1.length();i++)
    {
        if(isdigit(str1[i]))
        {
            v1[m]=(int)str1[i]-48;
            m++;
        }
    } 

    for(int i=0;i<str2.length();i++)
    {
        if(isdigit(str2[i]))
        {
            v2[n]=(int)str2[i]-48;
            n++;
        }
    } 

    int temp;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(v1[i]==v2[j])
            {
                temp = v1[i];
                v1[i] = v1[j];
                v1[j] = temp;    
            }
        }
    }
    
    int result = 0;

    for(int i=0;i<m;i++)
    {
        result = result + Xor(v1[i],v2[i]);
    }

    cout<<result<<endl;
}

/*
Sample Input:
[1,0,3]
[5,3,4]

Sample Output:
8

Explanation:
Rearrange nums2 so that it becomes [5,4,3].
The XOR sum is (1 XOR 5) + (0 XOR 4) + (3 XOR 3) = 4 + 4 + 0 = 8.
*/
