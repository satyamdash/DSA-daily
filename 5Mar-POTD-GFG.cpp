class Solution {
  public:
  bool static cmp(const string& a, const string& b) {
    return a.size() < b.size();
}

    int longestStringChain(vector<string>& words) {
        // Code here
        // Sort the words by length
    sort(words.begin(), words.end(), cmp);

    // Create an unordered map to store the 
    // maximum chain length for each word
    unordered_map<string, int> dp;

    int res = 1;

    // Iterate through each word in the sorted list of words
    for (const string& w : words) {
      
        dp[w] = 1; // Initialize length for the current word
      
        // Try removing one character at a time to 
       // check if it forms a valid predecessor
        for (int i = 0; i < w.size(); ++i) {
            string pred = w.substr(0, i) + w.substr(i + 1);
            if (dp.find(pred) != dp.end()) {
                dp[w] = max(dp[w], dp[pred] + 1);
            }
        }
      
        res = max(res, dp[w]);
    }

    return res;
    }
};

