class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        priority_queue<int,vector<int>,greater<int>>minheap;
        vector<int>Ans;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            minheap.push(arr[i]);
            if(minheap.size()>k)
            {
                minheap.pop();
            }
        }
        
        while(k--)
        {
            Ans.push_back(minheap.top());
            minheap.pop();
        }
        sort(Ans.rbegin(),Ans.rend());
        return Ans;
    }
};
