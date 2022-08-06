//best time to buy and sell stock
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin>>str;

    int min_ele=105,m,max_ele=-1;

    for(int i=0;i<str.length();i++)
    {
        if(isdigit(str[i]))
        {
            if(min_ele > (int)str[i])
            {
                min_ele = (int)str[i];
                m=i;
            }
        }
    }

    for(int i=m;i<str.length();i++)
    {
        if(isdigit(str[i]))
        {
            if(max_ele < (int)str[i])
            {
                max_ele = (int)str[i];
            }
        }
    }

    cout<<max_ele - min_ele<<endl;
}

//Sample Input :
//[7,1,5,3,6,4]
//Sample Output :
//Sample Output :
//5

//Explaination : Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
//Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
