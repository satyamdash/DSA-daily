class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        int tm=0;
        vector<vector<int>>Vis(n,vector<int>(m,0));

        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},tm});
                    Vis[i][j]=2;
                }
            }
        } 

        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};

        while(!q.empty())
        {
            int row=q.front().first.first;
            int col=q.front().first.second;
            int t=q.front().second;
            tm=max(tm,t);

            q.pop();

             for(int k=0;k<4;k++)
            {
                int nrow=row+delrow[k];
                int ncol=col+delcol[k];

                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && grid[nrow][ncol]==1 
                &&Vis[nrow][ncol]!=2)
                {
                    q.push({{nrow,ncol},t+1});
                     grid[nrow][ncol] = 2;
                    Vis[nrow][ncol]=2;
                }
            }


        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    return -1; // Not all oranges could rot
                }
            }
        }

        return tm;
    }
};