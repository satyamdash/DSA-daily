class Solution {
  public:
  
    int f(int idx,int W, vector<int> &val, vector<int> &wt,vector<vector<int>>&dp)
    {
        if(idx==0)
        {
            if(wt[idx]<=W)
            {
                return val[0];
            }
            else
            {
                return 0;
            }
        }
        
        if(dp[idx][W]!=-1) return dp[idx][W];
        //not-pick
        int nottake=f(idx-1,W,val,wt,dp);
        
        int take=0;
        //pick
        if(wt[idx]<=W)
        {
          take=val[idx]+f(idx-1,W-wt[idx],val,wt,dp);
        }

        
        return dp[idx][W]=max(take,nottake);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
                int n=val.size();
        vector<vector<int>> dp(n, vector<int>(W + 1, -1));

    
        return f(n-1,W,val,wt,dp);
    }
};