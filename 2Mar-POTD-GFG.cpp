class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
      int n = arr.size();

    // to store the results
    vector<int> res;

    // to store the max value
    priority_queue<pair<int, int> > heap;

    // Initialize the heap with the first k elements
    for (int i = 0; i < k; i++)
        heap.push({ arr[i], i });

    // The maximum element in the first window
    res.push_back(heap.top().first);

    // Process the remaining elements
    for (int i = k; i < arr.size(); i++) {

        // Add the current element to the heap
        heap.push({ arr[i], i });

        // Remove elements that are outside the current
        // window
        while (heap.top().second <= i - k)
            heap.pop();

        // The maximum element in the current window
        res.push_back(heap.top().first);
    }

    return res;
    }
};
