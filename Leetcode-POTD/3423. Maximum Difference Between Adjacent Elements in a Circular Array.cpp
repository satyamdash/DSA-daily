using namespace std;
#include<vector>
#include<cmath>
#include<algorithm>
class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return -1;
        int i=0;
        int j=1;
        int max_diff=-999999;
        while(j<n)
        {
            int temp=abs(nums[j]-nums[i]);
            if(temp>max_diff)
            {
                max_diff=temp;
            }
            i++;
            j++;
        }

        return max(max_diff,abs(nums[n-1]-nums[0]));

    }
};