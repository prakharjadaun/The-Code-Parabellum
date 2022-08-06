//Red light and green light
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int *arr = (int *)malloc(n*sizeof(int));
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }

        int counter=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]>k)
            {
                counter++;
            }
        }

        cout<<counter<<endl;
    }
}

/*
Sample Input:
3
4 10
2 13 4 16
5 8
9 3 8 8 4
4 6
1 2 3 4

Sample Output:
2
1
0

*/
