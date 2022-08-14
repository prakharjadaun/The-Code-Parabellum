#include<bits/stdc++.h>
#define ll long long
using namespace std;
string update(string s)
{
    ll  k;
    cin>> k;
    while(k--)
    {
        ll a, L, R;
        cin>>a>>L>>R;
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
    }
    s.replace(0,1,"");
    return s;
}

ll minToggle(string s)
{
    ll toggle=0, count_O=0,count_x=0;
    for(ll i=0;i<s.length();i++)
    {
        if(s[i]=='X')
        {
            count_x++;
        }
    }  
    toggle = count_x;
    for(ll i=0;i<s.length();i++)
    {
        if(s.at(i)=='O')
        count_O++;
        else
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
        string s,temp;
        cin>>temp;
        s = " "+temp;
        s = update(s);
        cout<<minToggle(s)<<endl;
    }
    return 0;
}

/*

Sample Input:

1
XOXO
2
2 1 2
1 3 4

Constraints:

1 ≤ T ≤ 5
1 ≤ Length of String ≤ 105
1 ≤ k ≤ 5*10^4
1 ≤ L ≤ R ≤ Length of String
a = 1 or 2

Output Format
For each test case, output a single integer, the answer that Mr. Swegwan requires.

Sample Output:
2

Explanation:

After the first update operation string becomes OOXO.
After the second update operation string becomes OOXX.
Now either the first two O's can be changed to X or the last two X's to O.
So the number of toggles required and hence the answer are 2.

*/

