class Solution {
    public:
  void fun(int ind, int n, int sum, vector<int>& temp, vector<int>& arr) {
    if (ind == n) {
        temp.push_back(sum);
        return;
    }
    // If this state has already been processed
    
    // Include current element
    fun(ind + 1, n, sum + arr[ind], temp, arr);
    
    // Exclude current element
    fun(ind + 1, n, sum, temp, arr);
}

vector<int> subsetSums(vector<int>& arr) {
    int n = arr.size();
    vector<int> temp; // To store subset sums
    fun(0, n, 0, temp, arr); // Start the recursive process
    sort(temp.begin(), temp.end()); // Sort the results
    return temp;
}
};