class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        // code here
        // length of arr
    int n = arr.size();

    // variable to store length of longest subarray
    int maxLen = 0;

    // variable to store beginning of the longest subarray
    int beginning = 0;

    // map to store the maximum and the minimum elements for
    // a given window
    map<int, int> window;

    // Initialize the window
    int start = 0, end = 0;

    // Loop through the array
    for (; end < n; end++) {
        
        // Increment the count of that element in the window
        window[arr[end]]++;

        // maximum and minimum element in current window
        auto minimum = window.begin()->first;
        auto maximum = window.rbegin()->first;

        // If the difference is not greater than X
        if (maximum - minimum <= x) {
            
            // Update the length of the longest subarray and
            // store the beginning of the sub-array
            if (maxLen < end - start + 1) {
                maxLen = end - start + 1;
                beginning = start;
            }
        }
        
        // Decrease the size of the window
        else {
            while (start < end) {
                
                // Remove the element at start
                window[arr[start]]--;

                // Remove the element from the window
                // if its count is zero
                if (window[arr[start]] == 0) {

                    window.erase(window.find(arr[start]));
                }
                
                // Increment the start of the window
                start++;

                // maximum and minimum element in the
                // current window
                auto minimum = window.begin()->first;
                auto maximum = window.rbegin()->first;

                // Stop decreasing the size of window
                // when difference is not greater
                if (maximum - minimum <= x)
                    break;
            }
        }
    }

    // Return the longest sub-array
    vector<int> res;
    for (int i = beginning; i < beginning + maxLen; i++)
        res.push_back(arr[i]);
        
    return res;
    }
};