//{ Driver Code Starts
using namespace std;
#include<vector>
#include<algorithm>
#include<queue>

// } Driver Code Ends

class Solution {
    
  public:
    static bool comp(const pair<int,int>&p1 ,const pair<int,int>&p2)
    {
        return p1.first<p2.first;
    }
    
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        vector<pair<int,int>>Pair;
        int platform=1;
        
        for(int i=0;i<arr.size();i++)
        {
            Pair.push_back({arr[i],dep[i]});
        }
        
        sort(Pair.begin(),Pair.end(),comp);
        
         priority_queue<int, vector<int>, greater<int>> pq; // Min-heap for departures
        pq.push(Pair[0].second);
        
        for(int i=1;i<arr.size();i++)
        {
            if(Pair[i].first>pq.top())
            {
                pq.pop();
            }
            pq.push(Pair[i].second);
            platform = max(platform, (int)pq.size());
        }
        
        return platform;
    }
};