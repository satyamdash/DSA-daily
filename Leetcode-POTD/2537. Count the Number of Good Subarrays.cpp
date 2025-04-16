//1st intution
class Solution {
public:
    bool isGoodSubarray(vector<int>&temp,int k)
    {
       unordered_map<int, int> mpp;
        long long totalPairs = 0;

        for (auto num : temp) {
            totalPairs += mpp[num]; // each existing `num` adds to the pair count
            mpp[num]++;
        }

        return totalPairs >= k;
    }
    long long countGood(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            vector<int>temp;
            for(int j=i;j<n;j++)
            {
                temp.push_back(nums[j]);
                if(isGoodSubarray(temp,k)) count++;
            }
        }
        return count;
    }
};

//2nd Intution

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n=nums.size();
        long long result=0;
        int i=0;
        int j=0;
        int pairs=0;
        unordered_map<int, int> mpp;

        while(j<n)
        {
            pairs+=mpp[nums[j]];
            mpp[nums[j]]++;

            while(pairs>=k)
            {
                result+=(n-j);
                mpp[nums[i]]--;
                pairs-=mpp[nums[i]];
                i++;
            }
            j++;
        }
        return result;
    }
};