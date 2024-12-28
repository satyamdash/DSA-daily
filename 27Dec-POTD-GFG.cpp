class Solution {
  public:
    int countPairs(vector<int> &arr, int target) 
    {
        int n=arr.size();
        unordered_map<int,int>mpp;
        int count=0;
        for(int i=0;i<n;i++)
        {
            int find=target-arr[i];
            if(mpp[find]>0)
            {
                count+=mpp[find];
            }
            
            mpp[arr[i]]++;
        }
        return count;
    }
};