class Solution {
public:
    void fun(int ind,int amount,vector<int>& candidates,vector<vector<int>>&Ans,vector<int>&temp)
    {
        if (ind == candidates.size()) 
        {
            if (amount == 0) 
            {
                Ans.push_back(temp);
            }
            return;
      }
        //pick
        if (candidates[ind] <= amount) 
        {
            temp.push_back(candidates[ind]);
            fun(ind, amount - candidates[ind], candidates, Ans, temp);
            temp.pop_back();
      }

        //not-pick
        fun(ind+1,amount,candidates,Ans,temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>>Ans;
        vector<int>temp;
        fun(0,target,candidates,Ans,temp);
        return Ans;
    }
};