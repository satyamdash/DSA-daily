class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
    vector<double> Ans;
        priority_queue<int> maxHeap; // Max heap for left half
        priority_queue<int, vector<int>, greater<int>> minHeap; // Min heap for right half
        
        for (int num : arr) {
            if (maxHeap.empty() || num <= maxHeap.top()) {
                maxHeap.push(num);
            } else {
                minHeap.push(num);
            }

            // Balance the heaps
            if (maxHeap.size() > minHeap.size() + 1) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            } else if (minHeap.size() > maxHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }

            // Compute median
            if (maxHeap.size() == minHeap.size()) {
                Ans.push_back((maxHeap.top() + minHeap.top()) / 2.0);
            } else {
                Ans.push_back(maxHeap.top());
            }
        }
        return Ans;
    }
};
