//{ Driver Code Starts
#include<vector>
#include<unordered_map>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) 
    {
        int n=arr.size();
        unordered_map<int,int>mpp;
        long currentxor=0;
        long count=0;
        mpp[0]=1;
        for(int i=0;i<n;i++)
        {
            currentxor^=arr[i];
            if(mpp.find(k^currentxor)!=mpp.end())
            {
                count+=mpp[k^currentxor];
            }
            mpp[currentxor]++;
        }
        return count;
        
    }
};