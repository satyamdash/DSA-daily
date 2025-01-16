using namespace std;
#include<vector>
#include<unordered_map>
class Solution {
  public:
    int maxLen(vector<int> &arr) 
    {
        int n=arr.size();
        unordered_map<int,int>mpp;
        int prefsum=0;
        
        int res=0;
        for(int i=0;i<n;i++)
        {
           prefsum+=(arr[i]==0)?-1:1;
           
           if(prefsum == 0) 
           {
            res = i + 1;
           }
           if(mpp.find(prefsum)!=mpp.end())
           {
               res=max(res,i-mpp[prefsum]);
           }
           
           else
           {
               mpp[prefsum]=i;
           }
        }
        
        return res;
    }
};
