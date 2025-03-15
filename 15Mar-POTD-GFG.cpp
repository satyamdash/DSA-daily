class Solution {
  public:
    int f(int idx,vector<int> &coins,int remain,vector<vector<int>>&dp)
    {
        
        if(remain==0)
        {
            return 0;
        }
        if(idx>=coins.size()||remain<0)
        {
            return 1e9;
        }
        
        if(dp[idx][remain]!=-1) return dp[idx][remain];
        int pick=1e9;
        //pick
        if (coins[idx] <= remain)
        {
             pick=1+f(idx,coins,remain-coins[idx],dp);
        }
        
        //not-pick
        int notpick=f(idx+1,coins,remain,dp);
        
        return dp[idx][remain]=min(pick,notpick);
    }
    
    int minCoins(vector<int> &coins, int sum) {
        // code here
        int n=coins.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        int remain=sum;
        int ans=f(0,coins,remain,dp);
        return ans==1e9?-1:ans;
    }
};
