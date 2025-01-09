//{ Driver Code Starts
using namespace std;
#include <vector>

// } Driver Code Ends
class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) 
    {
        int s=0,e=0;
        vector<int>Ans;
        int curr=0;
        int n=arr.size();
        
        for(int i=0;i<n;i++)
        {
            curr+=arr[i];
            if(curr>=target)
            {
                e=i;
                
                
                while(curr>target && s<e)
                {
                    curr-=arr[s];
                    ++s;
                }
                
                if(curr==target)
                {
                    Ans.push_back(s+1);
                    Ans.push_back(e+1);
                    return Ans;
                }
            }
        }
        Ans.push_back(-1);
        return Ans;
    }
};