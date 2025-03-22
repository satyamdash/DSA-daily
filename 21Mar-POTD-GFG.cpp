class Solution {
  public:
  // Calculate the maximum stolen value recursively
int maxLootRec(vector<int> &hval, int n,vector<int>&memo) {
    
    if (n <= 0) return 0;
    if (n == 1) return hval[0];

    // Check if the result is already computed
    if (memo[n] != -1) return memo[n];

    int pick = hval[n - 1] + maxLootRec(hval, n - 2, memo);
    int notPick = maxLootRec(hval, n - 1, memo);

    // Store the max of two choices in the memo array and return it
    memo[n] = max(pick, notPick);
    return memo[n];
}

    int findMaxSum(vector<int>& arr) {
        // code here
    int n = arr.size();
  
    // Initialize memo array with -1
    vector<int> memo(n + 1, -1); 
    return maxLootRec(arr, n, memo);
    }
};