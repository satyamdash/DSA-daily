class Solution {
public:
    void getperm(int idx,vector<int>&nums,vector<vector<int>>&Ans)
    {
        if(idx==nums.size())
        {
            Ans.push_back(nums);
        }
        for(int i=idx;i<nums.size();i++)
        {
            swap(nums[i],nums[idx]);
            getperm(idx+1,nums,Ans);
            swap(nums[i],nums[idx]);
        }
    } 

    string getPermutation(int n, int k) 
    {
        vector<int>nums;
        for(int i=1;i<=n;i++)
        {
            nums.push_back(i);
        }
        vector<vector<int>> Ans;
        getperm(0,nums,Ans);
        sort(Ans.begin(),Ans.end());
        string ans="";
        for(auto it:Ans[k-1])
        {
            ans+=to_string(it);
        }
        return ans;
    }
};