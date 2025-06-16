using namespace std;
#include<vector>
#include<algorithm>
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        
        int maxdiff=-1;
        int n=nums.size();
        if(n<2) return -1;
        int mini=nums[0];

        int j=1;
        int i=0;
        while(j<n)
        {
            mini=min(mini,nums[i]);
            if(nums[j]>mini)
            {
                maxdiff=max(maxdiff,nums[j]-mini);
            }      
            i++;
            j++;
        }

        return maxdiff;
    }
};