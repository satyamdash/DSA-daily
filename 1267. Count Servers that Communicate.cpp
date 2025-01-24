class Solution {
public:
    int countServers(vector<vector<int>>& grid) 
    {
       int row=grid.size();
       int col=grid[0].size();

       vector<int>rowcount(row,0);
       vector<int>colcount(col,0);
       for(int i=0;i<row;i++)
       {
        for(int j=0;j<col;j++)
        {
            if(grid[i][j]==1)
            {
                rowcount[i]++;
                colcount[j]++;
            }
        }
       }
        int result=0;
       for(int i=0;i<row;i++)
       {
        for(int j=0;j<col;j++)
        {
            if(grid[i][j]==1 && (rowcount[i]>1 || colcount[j]>1))
            {
                result++;
            }
        }
       }

       return result;
    }
};