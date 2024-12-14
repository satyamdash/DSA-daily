class Solution {
  public:
    int search(vector<int>& arr, int key) 
    {
        int n=arr.size();
        int low=0;
        int high=n-1;
        
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(arr[mid]==key) return mid;
            if(arr[low]<=arr[mid])
            {
                if(arr[low]<=key && arr[mid]>=key)
                {
                    high=mid-1;
                }
                else
                {
                    low=mid+1;
                }
            }
            else
            {
                if(arr[mid]<=key && arr[high]>=key)
                {
                    low=mid+1;
                }
                else
                {
                    high=mid-1;
                }
            }
        }
        return -1;
    }
};
