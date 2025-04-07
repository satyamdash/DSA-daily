#include<vector>
#include<algorithm>
using namespace std;


class Solution {
  public:
    static bool comp(const pair<int,int>p1,const pair<int,int>p2)
    {
        if(p1.second==p2.second)
        {
            return p1.first>p2.first;
        }
        
        return p1.second<p2.second;
    
    }
    int activitySelection(vector<int> &start, vector<int> &finish) {
        // code here
        int n=start.size();
        vector<pair<int,int>>p;
        for(int i=0;i<n;i++)
        {
            p.push_back({start[i],finish[i]});
        }
        
        sort(p.begin(),p.end(),comp);
        
        int ans=1;
        int last=p[0].second;
        
        for(int i=1;i<p.size();i++)
        {
            if(last<p[i].first)
            {
                ans++;
                last=p[i].second;
            }
            
        }
        
        return ans;
    }
};