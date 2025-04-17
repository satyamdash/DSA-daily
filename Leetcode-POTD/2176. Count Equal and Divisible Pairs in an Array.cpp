//1st Intution
class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if((nums[i]==nums[j]) && ((i*j)%k)==0)
                {
                    count++;
                }
            }
        }
        return count;
    }
};

//2nd Intution

class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0;
        unordered_map<int,vector<int>>mpp;

        for(int i=0;i<n;i++)
        {
           mpp[nums[i]].push_back(i);
        }

        for (auto& [val, indices] : mpp) {
        int sz = indices.size();
        // O(sz^2): check all pairs in that group
        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j < sz; j++) {
                if ((indices[i] * indices[j]) % k == 0)
                    count++;
        }
    }
}

        return count;
    }
};