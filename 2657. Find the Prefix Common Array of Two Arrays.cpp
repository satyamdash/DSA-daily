using namespace std;
#include<vector>
#include<unordered_map>
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) 
    {
      int n=A.size();
        int cnt=0;
        unordered_map<int,int>mpp;
        vector<int>Ans;
      for(int i=0;i<n;i++)
      {
        mpp[A[i]]++;
        mpp[B[i]]++;
        if(mpp[A[i]]>1)
        {
            cnt++;
        }
        if(mpp[B[i]]>1 && A[i]!=B[i])
        {
            cnt++;
        }
        Ans.push_back(cnt);
      }

      
    return Ans;
    }
};