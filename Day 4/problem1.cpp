#include<bits/stdc++.h>
using namespace std;
string update(string s,int a,int L,int R)
{
    char c;
    if(a==1)
    {
        string temp(R-L+1,'X');
        s.replace(L,R-L+1,temp);
    }
    else
    {
        string temp(R-L+1,'O');
        s.replace(L,R-L+1,temp);
    }
    return s;
}

int minToggle(string s)
{
    int toggle=0;
    int count_O=0,count_x=0;
    for(int i=0;i<s.length();i++)
    {
        if(s.at(i)=='X')
        {
            count_x++;
        }
    }  
    toggle = count_x;
    for(int i=0;i<s.length();i++)
    {
        if(s.at(i)=='O')
        count_O++;
        if(s.at(i)=='X')
        count_x--;
        toggle = min<int>(toggle,count_x+count_O);
    }
    return toggle;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        int k,a,L,R;

        cin>>s;
        cin>>k;
        while(k--)
        {
            cin>>a>>L>>R;
            s = update(s,a,L,R);
        }

        cout<<minToggle(s)<<endl;
    }
    return 0;
}