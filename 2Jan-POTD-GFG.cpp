using namespace std;
#include<vector>
#include<unordered_map>
class Solution {
  public:
    int countSubarrays(vector<int> &arr, int k) 
    {
        unordered_map<int,int>mpp;
        int n=arr.size();
        int currentsum=0;
        int cnt=0;
        mpp[0]=1;
        for(int i=0;i<n;i++)
        {
            currentsum+=arr[i];
            if(mpp.find(currentsum-k)!=mpp.end())
            {
                cnt+=mpp[currentsum-k];
            }
            mpp[currentsum]++;

        }
        return cnt;
    }
};