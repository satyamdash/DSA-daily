class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        int n = nums.size();
    std::unordered_map<int, int> mpp;

    // Step 1: Count frequencies
    for (int i = 0; i < n; i++) {
        mpp[nums[i]]++;
    }

 // Step 2: Max-heap to store {frequency, number}
    // Custom comparator to compare based on frequency (second element of the pair)
    auto compare = [](std::pair<int, int>& a, std::pair<int, int>& b) {
        return a.second < b.second;  // Min-heap comparison: lower frequency comes first
    };

    // Priority queue with the custom comparator (max-heap by frequency)
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(compare)> maxheap(compare);
    for (const auto& entry : mpp) {
        maxheap.push(entry); // Push the {frequency, element} pair
    }

    // Step 3: Extract top k elements
    std::vector<int> result;
    for (int i = 0; i < k; i++) {
        result.push_back(maxheap.top().first); // Get the element (first part of pair)
        maxheap.pop(); // Pop the top element
    }

    return result;
    }
};