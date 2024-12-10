class Solution {
  public:
    int minRemoval(vector<vector<int>> &intervals) 
    {
      int count=0;
      sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
      vector<int>Currentinterval=intervals[0];
      
      for(int i=1;i<intervals.size();i++)
      {
          if(Currentinterval[1]>intervals[i][0])
          {
              count++;
          }
          else
          {
              Currentinterval=intervals[i];
          }
      }
      
      return count;
    }
};
