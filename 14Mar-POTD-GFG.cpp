class Solution {
  public:
  
    int f(int idx,vector<int>& coins, int sum,int total,vector<vector<int>>&dp)
    {
        if(sum<total)
        {
            return 0;
        }
        if(sum==total)
        {
            return 1;
        }
        if(idx>=coins.size())
        {
            return 0;
        }
        if(dp[idx][total]!=-1) return dp[idx][total];
        //pick
        int pick=f(idx,coins,sum,coins[idx]+total,dp);
        
        //not pick
        int notpick=f(idx+1,coins,sum,total,dp);
        
        return dp[idx][total]=pick+notpick;
    }
    int count(vector<int>& coins, int sum) {
        // code here.
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(1001,-1));
        int total=0;
        return f(0,coins,sum,total,dp);
    }
};