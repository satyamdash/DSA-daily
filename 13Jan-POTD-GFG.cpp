using namespace std;
#include<vector>

// } Driver Code Ends
class Solution {

  public:
    int maxWater(vector<int> &arr) 
    {
        int maxi=0;
        int n=arr.size();
        
        int left=0;
        int right=n-1;
        
        while(left<right)
        {
           maxi=max(maxi,min(arr[left],arr[right])*(right-left));
           if(arr[left]<arr[right])
           {
               left++;
           }
           else
           {
               right--;
           }
        }
        return maxi;
    }
};
