class Solution {
public:
    bool f(int idx,vector<int>& nums,int sum,vector<vector<int>>&dp)
    {
        if(sum==0) return true;
        if(idx>=nums.size()) return false;
        if(sum<0) return false;

        if(dp[idx][sum]!=-1) return dp[idx][sum];
        bool pick=f(idx+1,nums,sum-nums[idx],dp);

        bool notpick=f(idx+1,nums,sum,dp);

        return dp[idx][sum]=pick||notpick;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;

        for(auto num:nums)
        {
            sum+=num;
        }
        if(sum%2!=0) return false;
        int total=sum/2;
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return f(0,nums,total,dp);
    }
};