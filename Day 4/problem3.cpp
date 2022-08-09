#include<bits/stdc++.h>
using namespace std;
int truckTour(vector<vector<int>> petrolpumps) 
{
    int n = petrolpumps.size();
    int petleft = 0;
    int index = 0;
    
    for (int i=0; i<n; i++)
    { 
        petleft += petrolpumps[i][0] - petrolpumps[i][1];
        if (petleft < 0){
            index = i+1;
            petleft = 0;
        }
    }
    return index;
}