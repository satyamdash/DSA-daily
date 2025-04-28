class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n=nums.size();
        long long count=0;
        long long sum=0;
        long long prod=1;
        int i=0;
        int j=0;
        
        while(j<n)
        {
            sum+=nums[j];
            prod=sum*(j-i+1);
            while(prod>=k)
            {
                sum-=nums[i];
                i++;
                prod=sum*(j-i+1);
            }
            if(prod<k) count+=(j-i+1);
        
            j++;
        }


        return count;
    }
};