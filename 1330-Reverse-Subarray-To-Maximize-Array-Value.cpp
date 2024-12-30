class Solution {
public:
    int maxValueAfterReverse(vector<int>& nums) 
    {
    int n = nums.size();
    int initBeauty = 0;

    // Step 1: Calculate initial beauty
    for (int i = 1; i < n; i++) {
        initBeauty += abs(nums[i] - nums[i - 1]);
    }

    int maxGain = 0;

    // Step 2: Analyze boundary contributions
    // Case 1: Reverse affecting the left boundary (l > 0)
    for (int i = 1; i < n; i++) {
        maxGain = max(maxGain, abs(nums[i] - nums[0]) - abs(nums[i] - nums[i - 1]));
    }

    // Case 2: Reverse affecting the right boundary (r < n - 1)
    for (int i = 0; i < n - 1; i++) {
        maxGain = max(maxGain, abs(nums[i] - nums[n - 1]) - abs(nums[i + 1] - nums[i]));
    }

    // Case 3: Minimize beauty loss in the middle of the array
    int minBoundary = INT_MAX, maxBoundary = INT_MIN;
    for (int i = 1; i < n; i++) {
        int low = min(nums[i], nums[i - 1]);
        int high = max(nums[i], nums[i - 1]);
        minBoundary = min(minBoundary, high);
        maxBoundary = max(maxBoundary, low);
    }
    maxGain = max(maxGain, 2 * (maxBoundary - minBoundary));

    return initBeauty + maxGain;
    }
};