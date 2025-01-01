using namespace std;
#include<vector>
#include<queue>
class Solution {
  public:
    void BFS(int row,int col,vector<vector<int>>& grid,vector<vector<int>>&Vis,int n,int m,vector<pair<int,int>>&vec)
    {
        Vis[row][col]=1;
        queue<pair<int,int>>q;
        q.push({row,col});
        
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        
        
        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow=r+delrow[i];
                int ncol=c+delcol[i];
                
                if(nrow<n && ncol<m && ncol>=0 && nrow>=0 &&
                !Vis[nrow][ncol] && grid[nrow][ncol]==1)
                {
                    q.push({nrow,ncol});
                    Vis[nrow][ncol]=1;
                    vec.push_back({nrow-row,ncol-col});
                }
            }
        }
    }
    
    int countDistinctIslands(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        set<vector<pair<int,int>>>st;
        
        vector<vector<int>>Vis(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && !Vis[i][j])
                {
                    vector<pair<int,int>>vec;
                    BFS(i,j,grid,Vis,n,m,vec);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};