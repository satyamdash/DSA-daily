using namespace std;
#include<vector>

// } Driver Code Ends
class Solution {
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) 
    {

        int n=arr.size();
        int sum=0;
        vector<int>prefixsum(n,0);
        vector<int>suffixsum(n,0);
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            prefixsum[i]=sum;
        }
        sum=0;
        for(int i=n-1;i>=0;i--)
        {
            sum+=arr[i];
            suffixsum[i]=sum;
        }
        for(int i=1;i<n-1;i++)
        {
            if(prefixsum[i-1]==suffixsum[i+1])
            {
                return i;
            }
        }
        
        return -1;
    }
};