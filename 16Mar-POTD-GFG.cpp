class Solution {
  public:
    
    int f(int idx,vector<int>&arr,vector<int>&dp)
    {
        if(idx>=arr.size()-1)
        {
            return 0;
        }
        
        if (arr[idx] == 0) return 1e9;
        
        int mini=1e9;
        if(dp[idx]!=-1) return dp[idx];
        if(arr[idx]!=0)
        {
            for(int i=1;i<=arr[idx];i++)
            {
                mini=min(mini,1+f(idx+i,arr,dp));
            }
        }
        return dp[idx]= mini;
    }
    
    int minJumps(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int>dp(n,-1);
        if(arr[0]==0) return -1;
        int ans=f(0,arr,dp);
        return ans==1e9?-1:ans;
    }
};

