class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        vector<vector<int>>Ans;
        priority_queue<pair<int, vector<int>>> maxHeap;
        for(auto point:points)
        {
            int x=point[0];
            int y=point[1];
            
            double dist=x*x+y*y;
            
            maxHeap.push({dist,point});
            if(maxHeap.size()>k)
            {
                maxHeap.pop();
            }
        }
        
        while(!maxHeap.empty())
        {
            Ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        
        return Ans;
    }
};