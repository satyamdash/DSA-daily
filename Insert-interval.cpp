class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals,
                                       vector<int> &newInterval) 
    {
        
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>Ans;
        vector<int>CurrentInterval;
        
        CurrentInterval=intervals[0];
        
        for(int i=1;i<intervals.size();i++)
        {
            if(CurrentInterval[1]>=intervals[i][0])
            {
                CurrentInterval[1]=max(intervals[i][1],CurrentInterval[1]);
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