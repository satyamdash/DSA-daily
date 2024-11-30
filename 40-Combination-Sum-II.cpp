class Solution {
public:
void fun(int ind,int amount,vector<int>& candidates,vector<vector<int>>&Ans,vector<int>&temp)
    {
       
            if (amount == 0) 
            {
                Ans.push_back(temp);
            }
        for(int i=ind;i<candidates.size();i++)
        {
            if(i>ind && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>amount) break;
            temp.push_back(candidates[i]);
            fun(i+1,amount-candidates[i],candidates,Ans,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        vector<vector<int>>Ans;
        vector<int>temp;
        sort(candidates.begin(),candidates.end());
        fun(0,target,candidates,Ans,temp);
        return Ans;
    }
};