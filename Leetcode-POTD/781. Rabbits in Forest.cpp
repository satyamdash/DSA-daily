class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> freq;
    for (int ans : answers) {
        freq[ans]++;
    }

    int total = 0;
    for (auto& [k, count] : freq) {
        int groupSize = k + 1;
        int groups = ceil((double)count / groupSize);
        total += groups * groupSize;
    }

    return total;
    }
};