class Solution {
  public:
    
    int dfs(vector<int>& cost,int i,vector<int>&dp)
    {
        if(i>=cost.size())
        {
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        return dp[i]=cost[i]+min(dfs(cost,i+1,dp),dfs(cost,i+2,dp));
       
    }
    int minCostClimbingStairs(vector<int>& cost) {
       int n =cost.size();
        vector<int>dp(n+1,-1);
         return min(dfs(cost, 0,dp), dfs(cost, 1,dp));
    }
};