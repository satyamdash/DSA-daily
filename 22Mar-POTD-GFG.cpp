class Solution {
  public:
    int f(int idx,vector<int>& arr,vector<int>&dp)
    {
        if(idx>=arr.size())
        {
            return 0;
        }
        if(dp[idx]!=-1) return dp[idx];
        //loot
        int pick=f(idx+2,arr,dp)+arr[idx];
        //skip
        int notpick=f(idx+1,arr,dp);
        
        return dp[idx]=max(pick,notpick);
    }
    
    int maxValue(vector<int>& arr) {
        // your code here
        int n=arr.size();
        vector<int>dp(n+1,-1);
        vector<int>firstinclude(arr.begin(),arr.end()-1);
        vector<int>lastinclude(arr.begin()+1,arr.end());
        int a1=f(0,firstinclude,dp);
        vector<int>dp1(n+1,-1);
        int a2=f(0,lastinclude,dp1);
        
        return max(a1,a2);
    }
};