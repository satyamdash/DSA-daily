// 1st Intution
class Solution {
public:
    bool checkDistinct(vector<int>&arr,int idx)
    {
        int n=arr.size()-idx;
        unordered_set<int>s(arr.begin()+idx,arr.end());

        return n==s.size();
    }
    int minimumOperations(vector<int>& nums) {

        int n=nums.size();
        int maxop=0;

        for(int i=0;i<n;i=i+3)
        {
            if(checkDistinct(nums,i))
            {
                return maxop;
            }
            else
            {
                maxop++;
            }
        }

        return maxop;
    }
};

//2nd Intution

int minimumOperations(vector<int>& nums) {

        int n=nums.size();
        int maxop=0;
        // if(checkDistinct(nums,0))
        unordered_map<int,int>mpp;

        for(int i=n-1;i>=0;i--)
        {
            if(mpp[nums[i]]>=1)
            {
                int idx=i+1;
                if(idx%3==0)
                {
                    maxop=idx/3; 
                }
                else
                {
                    maxop=idx/3+1;
                }
                break;
            }
            mpp[nums[i]]++;
        }
        return maxop;
    }