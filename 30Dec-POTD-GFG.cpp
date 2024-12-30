class Solution {
  public:
    // Function to return the count of number of elements in union of two arrays.
    int findUnion(vector<int>& a, vector<int>& b) 
    {
        unordered_set<int>St;
        
        for(int i=0;i<a.size();i++)
        {
             St.insert(a[i]);
        }
        for(int j=0;j<b.size();j++)
        {
             St.insert(b[j]);
        }
        return St.size();
    }
};

