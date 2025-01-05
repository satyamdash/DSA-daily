using namespace std;
#include<vector>
#include<algorithm>
class Solution {
  public:
    int countPairs(vector<int> &arr, int target) 
    {
        int n=arr.size();
        int cnt=0;
        int sum=0;
        sort(arr.begin(),arr.end());
        
        int low=0;
        int high=n-1;
        while(low<high)
        {
            sum=arr[low]+arr[high];
            if(sum<target)
            {
                cnt+=high-low;
                low++;
 
            }
            else
            {
                high--;
            }
        }
        return cnt;
    }
};
