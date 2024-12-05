//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void sort012(vector<int>& arr) 
    {
        int left=0;
        int n=arr.size();
        int right=n-1;
        int i=0;
        while(i<=right)
        {
            if(arr[i]==1)
            {
                i++;
            }
            else if(arr[i]==0)
            {
                swap(arr[i],arr[left]);
                left++;
                i++;
            }
            else if(arr[i]==2)
            {
                swap(arr[i],arr[right]);
                right--;
            }
        }
    }
};