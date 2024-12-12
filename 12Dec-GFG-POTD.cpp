class Solution {
  public:
    int countFreq(vector<int>& arr, int target) 
    {
        unordered_map<int,int>mpp;
        
        for(int i=0;i<arr.size();i++)
        {
            mpp[arr[i]]++;
        }
        
        return mpp[target];
    }
};

