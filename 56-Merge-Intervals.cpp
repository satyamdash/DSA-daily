class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        int m=intervals.size();
        if(m==0) return intervals;
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>Ans;
        vector<int>CurrentInterval;
        
        CurrentInterval=intervals[0];
 
      for(int i=1;i<m;i++)
      {
         if(CurrentInterval[1]>=intervals[i][0])
         {
           CurrentInterval[1]=max(CurrentInterval[1],intervals[i][1]);
         }
         else
         {
           Ans.push_back(CurrentInterval);
           CurrentInterval=intervals[i];
         }

      } 
      Ans.push_back(CurrentInterval);
      return Ans;
    }
};