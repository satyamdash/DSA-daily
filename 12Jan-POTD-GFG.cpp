using namespace std;
#include<vector>

class Solution {
  public:
    int maxWater(vector<int> &arr) 
    {
        int n=arr.size();
        
        vector<int>prefix(n,0);
        vector<int>suffix(n,0);
        prefix[0]=arr[0];
        suffix[n-1]=prefix[n-1];
        int maxi=-1;
        for(int i=1;i<n;i++)
        {
            maxi=max(maxi,arr[i-1]);
            prefix[i]=maxi;
        }
        maxi=-1;
        for(int i=n-2;i>=0;i--)
        {
            maxi=max(maxi,arr[i+1]);
            suffix[i]=max(maxi,arr[i+1]);
        }
        
        int output=0;
        
        for(int i=0;i<n;i++)
        {
             output += max(0, min(prefix[i], suffix[i]) - arr[i]);
        }
        
        return output;
    }
};