class Solution {
  public:
    int f(int idx,string &digits,int n,vector<int>&dp)
    {
        if(idx==n) return 1;
        
        if(digits[idx]=='0') return 0;
        
        if(dp[idx]!=-1) return dp[idx];
        int result=f(idx+1,digits,n,dp);
        
        if(idx+1<n)
        {
            if(digits[idx]=='1' || (digits[idx]=='2' && digits[idx+1]<='6'))
            {
                 result+=f(idx+2,digits,n,dp);
            }
        }
        
        return dp[idx]=result;
    }

    int countWays(string &digits) {
        // Code here
        vector<int>dp(digits.length()+1,-1);
        return f(0,digits,digits.length(),dp);
    }
};