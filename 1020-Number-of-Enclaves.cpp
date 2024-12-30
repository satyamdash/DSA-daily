class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) 
    {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>Vis(m,vector<int>(n,0));


        for(int col=0;col<n;col++)
        {
            if(grid[0][col]==1)
            {
                Vis[0][col]=1;
                q.push({0,col});
            }
        }

        for(int row=0;row<m;row++)
        {
            if(grid[row][0]==1)
            {
                Vis[row][0]=1;
                q.push({row,0});
            }
        }

        for(int col=0;col<n;col++)
        {
            if(grid[m-1][col]==1)
            {
                Vis[m-1][col]=1;
                q.push({m-1,col});
            }
        }


        for(int row=0;row<m;row++)
        {
            if(grid[row][n-1]==1)
            {
                Vis[row][n-1]=1;
                q.push({row,n-1});
            }
        }

        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};

        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow=row+delrow[i]; 
                int ncol=col+delcol[i];
            

            if(nrow>=0 && ncol>=0 && nrow<m && ncol<n &&
            grid[nrow][ncol]==1 && !Vis[nrow][ncol])
            {
                Vis[nrow][ncol]=1;
                q.push({nrow,ncol});
            }
            }
        }
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1 && Vis[i][j]==0)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};