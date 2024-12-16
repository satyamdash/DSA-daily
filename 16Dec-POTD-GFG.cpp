class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) 
    {
        int m=a.size();
        int n=b.size();
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(int i=0;i<m;i++)
        {
            minHeap.push(a[i]);
        }
        
        for(int i=0;i<n;i++)
        {
            minHeap.push(b[i]);
        }
        
        while(k>1)
        {
            minHeap.pop();
            k--;
        }
        return minHeap.top();
        
    }
};