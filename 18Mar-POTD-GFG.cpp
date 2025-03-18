class Solution {
  public:
  
    int f(int idx,vector<int>&arr,int sum,vector<vector<int>>&dp)
    {
        if(sum==0) return true;
        if(idx<0) return false;
        
        if(dp[idx][sum]!=-1) return dp[idx][sum];
        if(arr[idx]>sum) return dp[idx][sum]=f(idx-1,arr,sum,dp);

        return dp[idx][sum]=f(idx-1,arr,sum-arr[idx],dp) || f(idx-1,arr,sum,dp);
    }
    bool equalPartition(vector<int>& arr) {
        // code here
        int sum=0;
        int n=arr.size();

        for(auto num:arr)
        {
            sum+=num;
        }
        
        if(sum%2!=0) return false;
        int target = sum / 2;
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return f(n-1,arr,sum/2,dp);
    }
};
