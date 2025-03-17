class Solution {
  public:
  
    int f(int idx,vector<int>& arr, int sum,vector<vector<int>>&dp)
    {
        if(sum==0)
        {
            return 1;
        }
        
        if(idx>=arr.size() || sum<0)
        {
            return 0;
        }
        if(dp[idx][sum]!=-1) return dp[idx][sum];
        int pick=0;
        if(sum>=arr[idx])
        {
            //pick
             pick=f(idx+1,arr,sum-arr[idx],dp);
        }
        
        //not-pick
        int notpick=f(idx+1,arr,sum,dp);
        
        return dp[idx][sum]=pick || notpick ;
        
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return f(0,arr,sum,dp);
    }
};

