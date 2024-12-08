class Solution {
  public:
    // Function to find hIndex
    int hIndex(vector<int>& citations) 
    {
        int maxi=0;
      sort(citations.begin(),citations.end(),std::greater<int>());
      
      for(int i=0;i<citations.size();i++)
      {
        if(citations[i]>=i+1)
        {
            maxi=max(i+1,maxi);
        }
      }
      return maxi;
    }
};