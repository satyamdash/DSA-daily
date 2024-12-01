class Solution {
public:
    void getperm(int ind,int n,vector<int>&nums,vector<vector<int>>&Ans)
    {
        if(ind==n)
        {
            Ans.push_back(nums);
            return;
        }
        for(int i=ind;i<n;i++)
        {
            swap(nums[i],nums[ind]);
            getperm(ind+1,n,nums,Ans);
            swap(nums[i],nums[ind]);
        } 
    } 
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>>Ans;
        int n=nums.size();
         getperm(0,n,nums,Ans); 
         return Ans;
    }
};