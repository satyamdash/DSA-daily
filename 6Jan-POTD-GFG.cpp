using namespace std;
#include<vector>
#include<algorithm>

// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        // code here
        

        int n=arr.size();
        int sum=0;
        vector<int>Ans;
        int mindiff=INT_MAX;
                
        if(arr.size()<2) return Ans;
        
        
        sort(arr.begin(),arr.end());
        int low=0;
        int high=n-1;
        
        while(low<high)
        {
            int sum=arr[low]+arr[high];
            
            if(abs(target-sum)<mindiff)
            {
                mindiff=abs(target-sum);
                Ans={arr[low],arr[high]};
            }
            
            if(sum<target)
            {
                low++;
            }
            else if(sum>target)
            {
                high--;
            }
            else
            {
                return Ans;
            }
        }
        
        
        return Ans;
    }
};