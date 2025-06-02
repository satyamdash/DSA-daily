#include<iostream>
using namespace std;

class Solution {
public:
    long long Solve(int child,int candies,int limit)
    {
        if(child==3)
        {
            if(candies==0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        long long ways=0;
        for(int i=0;i<=min(candies,limit);i++)
        {
            ways+=Solve(child+1,candies-i,limit);
        }
        return ways;

    }
    long long distributeCandies(int n, int limit) {
        return Solve(0,n,limit);
    }
};