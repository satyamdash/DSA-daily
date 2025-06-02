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


//2nd Approach
class Solution {
public:
    long long distributeCandies(int n, int limit) {
         long long ways = 0;

        //child1
        int minCh1 = max(0, n - 2*limit);
        int maxCh1 = min(n, limit);

        for(int i = minCh1; i <= maxCh1; i++) { //fixing child1 assignment of candies

            int N = n-i; //for ch2 and ch3

            int minCh2 = max(0, N - limit);
            int maxCh2 = min(N, limit);

            ways += maxCh2 - minCh2 + 1;
        }

        return ways;
    }
};