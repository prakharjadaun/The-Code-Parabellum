//largest rectangle
#include <bits/stdc++.h>
using namespace std;

long largestRectangle(vector<int> h)
{

    int n = h.size();
    vector<int> stack;
    long maxArea = 0;
    for (int i = 0; i <= n; i++)
    {
        int temp = i == n ? 0 : h[i];
        while (stack.size() > 0 && temp < h[stack.back()])
        {
            int curHeight = h[stack.back()];
            stack.pop_back();
            int prevIndex = stack.size() == 0 ? -1 : stack.back();
            int area = curHeight * (i - prevIndex - 1);
            maxArea = max<int>(maxArea, area);
        }
        stack.push_back(i);
    }

    return maxArea;
}

int main()
{
    int n, val;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        v.push_back(val);
    }

    cout << largestRectangle(v) << endl;
    return 0;
}

/*
Sample Input : 
5
1 2 3 4 5

Sample Output:
9
*/