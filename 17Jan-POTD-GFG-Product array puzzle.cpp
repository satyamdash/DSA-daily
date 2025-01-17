using namespace std;
#include<vector>
class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) 
    {
        int total=1;
        int zeros=0;
        int n=arr.size();
        vector<int>Ans(n,0);
        int idx=-1;
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]!=0)
            {
                total*=arr[i];
            }
            else
            {
                zeros++;
                idx = i;
            }
        }
        
        if(zeros==0)
        {
            for(int i=0;i<n;i++)
            {
              Ans[i]=total/arr[i];
            }
        }
         else if (zeros == 1)
         {
                Ans[idx] = total;
         }
        
        return Ans;
    }
};