class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) 
    {
        unordered_set<int> s(arr.begin(), arr.end());
        
       int n=arr.size();
       int count=0;
       int curr=0;
        while(count<k)
        {
            curr++;
            if(s.find(curr)==s.end())
            {
                count++;
            }
            
        }
        return curr;
    }
    
};

