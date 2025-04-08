class Solution {
public:
    bool checkDistinct(vector<int>&arr,int idx)
    {
        int n=arr.size()-idx;
        unordered_set<int>s(arr.begin()+idx,arr.end());

        return n==s.size();
    }
    int minimumOperations(vector<int>& nums) {

        int n=nums.size();
        int maxop=0;

        for(int i=0;i<n;i=i+3)
        {
            if(checkDistinct(nums,i))
            {
                return maxop;
            }
            else
            {
                maxop++;
            }
        }

        return maxop;
    }
};