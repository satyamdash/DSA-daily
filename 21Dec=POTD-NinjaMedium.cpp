#include <bits/stdc++.h> 
int gcd(int a,int b)
{
    while(b!=0)
    {
        int temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}
bool isPossibleToSplit(int n, vector<int> &arr) 
{
    unordered_map<int,int>mpp;

    for(int i=0;i<n;i++)
    {
        mpp[arr[i]]++;
    }

    int overallgcd=0;
    for(auto pair: mpp)
    {
        overallgcd=gcd(overallgcd,pair.second);

        if (overallgcd == 1) {
          return false;
        }
    }

    return overallgcd>1;
}