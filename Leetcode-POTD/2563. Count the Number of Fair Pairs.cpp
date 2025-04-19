class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long count = 0;

        for (int i = 0; i < n; ++i) {
            int minSum = lower - nums[i];
            int maxSum = upper - nums[i];

            // Binary search in the subarray nums[i+1 ... n-1]
            auto low = lower_bound(nums.begin() + i + 1, nums.end(), minSum);
            auto high = upper_bound(nums.begin() + i + 1, nums.end(), maxSum);

            count += high - low;
        }

        return count;
    }
};