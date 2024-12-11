class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) 
    {
      int n=a.size();
      int m=b.size();
      
      
      vector<int>Merge;
      int i=0,j=0;
      while(i<n && j<m)
      {
          if(a[i]<=b[j])
          {
              Merge.push_back(a[i++]);
          }
          else
          {
              Merge.push_back(b[j++]);
          }
      }
      
      while(i<n)
      {
         Merge.push_back(a[i++]); 
      }
      
     while(j<m)
      {
         Merge.push_back(b[j++]); 
      }
      
      for(int i=0;i<n;i++)
      {
          a[i]=Merge[i];
      }
      for(int i=0;i<m;i++)
      {
          b[i]=Merge[n+i];
      }
    }
};