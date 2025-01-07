using namespace std;
#include<vector>

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) 
    {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int sum=0;
        int low=0;
        int high=n-1;
        
        int cnt=0;
        
        while(low<=high)
        {
            sum=arr[low]+arr[high];
            
            if(sum==target)
            {
                int ele1=arr[low];
                int ele2=arr[high];
                int cnt1=0;
                int cnt2=0;
                while(low<=high && arr[low]==ele1)
                {
                  low++;
                  cnt1++;
                }
                
                while(low<=high && arr[high]==ele2)
                {
                    high--;
                    cnt2++;
                }
                
                if(ele1==ele2)
                {
                    cnt+=(cnt1*(cnt1-1)/2);
                }
                
                cnt+=cnt2*cnt1;
            }
            else if(sum<target)
            {
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