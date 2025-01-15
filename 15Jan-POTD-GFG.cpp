using namespace std;
#include<vector>
#include<unordered_map>

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) 
    {
        unordered_map<int,int>mpp;
        int n=arr.size();
        int prefsum=0;
        int res=0;
        for(int i=0;i<n;i++)
        {
            prefsum+=arr[i];
            
            if(prefsum==k)
            {
                res=i+1;
            }
            if(mpp.find(prefsum-k)!=mpp.end())
            {
                res=max(res,i-mpp[prefsum-k]);
            }
        
            if(mpp.find(prefsum)==mpp.end())
            {
                mpp[prefsum]=i;
            }
        
        }
        return res;
    }
};