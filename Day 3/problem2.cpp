//Game of two stacks
#include <bits/stdc++.h>
using namespace std;

int twoStacks(int maxSum, vector<int> a, vector<int> b) 
{
    int result=0;
    int counter=0,i=0,j=0;

    for(;i<a.size() && result+a[i]<=maxSum;i++)
    {
        result = result +a[i];
    }
    counter=i;
    while(j<b.size() && i>=0)
    {
        result = result + b[j];
        j++;

        while(result>maxSum && i>0)
        {
            i--;
            result = result - a[i];
        }
        if(result<=maxSum && i+j>counter)
        counter=i+j;
    }

    return counter;
}

int main()
{
    int t;
    cin >> t;
    int val;
    while (t--)
    {
        int n, m, maxSum;
        cin >> n >> m >> maxSum;
        vector<int> a(n), b(m);
        for (int i = 0; i < n; i++)
        {
            cin >> val;
            a.push_back(val);
        }

        for (int i = 0; i < m; i++)
        {
            cin >> val;
            b.push_back(val);
        }

        cout << twoStacks(maxSum, a, b) << endl;
    }
    return 0;
}
/*
Sample Input :
1
5 4 10
4 2 4 6 1
2 1 8 5

Sample Output:
4
*/