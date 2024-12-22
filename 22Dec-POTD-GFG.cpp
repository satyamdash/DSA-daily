class Solution {
  public:
    bool matSearch(vector<vector<int>> &mat, int x) 
    {
        int n=mat.size();
        int m=mat[0].size();
        int i=0,j=m-1;
        
        while(i<n && j>=0)
        {
            if(x>mat[i][j])
            {
                i++;
            }
            else if(x<mat[i][j])
            {
                j--;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
    
};
