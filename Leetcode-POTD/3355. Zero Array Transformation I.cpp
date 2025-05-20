class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();

        vector<int>diff(n,0);

        for(auto &query:queries)
        {
            int start=query[0];
            int end=query[1];
            
            diff[start]+=1;

            if(end+1<n)
            {
                diff[end+1]-=1;
            }
        }

        vector<int>result(n,0);
        int cumsum=0;
        for(int i=0;i<n;i++)
        {
            cumsum+=diff[i];
            result[i]=cumsum;
        }

        for(int i=0;i<n;i++)
        {
            if(result[i]<nums[i])
            {
                return false;
            }
        }   
        return true;
    }
};