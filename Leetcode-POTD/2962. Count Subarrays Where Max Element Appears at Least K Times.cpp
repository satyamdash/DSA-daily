class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        long long maxelement=*max_element(nums.begin(), nums.end());
        int i=0;
        int j=0;
        long long count=0;
        long long freq=0;
        while(j<n)
        {
            if(nums[j]==maxelement)
            {
                freq++;
            }

            while(freq>=k)
            {
              count+= (n-j);
              
              if(nums[i]==maxelement)
              {
                freq--;
              }
              i++;
            }

            j++;
        }
        return count;
    }
};