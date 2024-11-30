class Solution {
public:
    void fun(int ind,vector<int>& nums,vector<vector<int>> &Ans,vector<int>& ds)
    {
        Ans.push_back(ds);
        for (int i = ind; i < nums.size(); i++) 
        {
             if (i != ind && nums[i] == nums[i - 1]) continue;
            ds.push_back(nums[i]);
            fun(i + 1, nums, Ans, ds);
            ds.pop_back();
         }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
      vector<vector<int>> Ans;
        vector<int> ds;
     sort(nums.begin(), nums.end());
        
      fun(0,nums,Ans,ds);
      return Ans;  
    }
};