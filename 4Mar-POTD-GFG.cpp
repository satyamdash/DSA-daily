class Solution {
  public:
    int lis(vector<int>& arr) {
        // code here
        int n = arr.size();
    if (n == 0) return 0;

    // Create a dp array, initialized to 1 (each element is a subsequence of length 1)
    vector<int> dp(n, 1);

    // Compute dp values
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    // The length of the longest increasing subsequence will be the max value in dp[]
    return *max_element(dp.begin(), dp.end());
        
    }
};