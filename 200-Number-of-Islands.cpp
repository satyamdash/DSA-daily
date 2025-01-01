
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    void bfs(int row,int col,vector<vector<int>>& Vis,vector<vector<char>>& grid,int n,int m)
    {
        Vis[row][col]=1;
        queue<pair<int,int>>q;
        q.push({row,col});

        while(!q.empty())
        {
            int currrow=q.front().first;
            int currcol=q.front().second;
            q.pop();
            int delrow[]={-1,0,1,0};
            int delcol[]={0,1,0,-1};
            for(int i=0;i<4;i++)
            {
                    int nrow=currrow+delrow[i];
                    int ncol=currcol+delcol[i];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' && !Vis[nrow][ncol])
                    {
                        Vis[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    }
                }
        }

    }
    int numIslands(vector<vector<char>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> Vis(n,vector<int>(m,0));
        int cnt=0;

        for(int row=0;row<n;row++)
        {
            for(int col=0;col<m;col++)
            {
                if(grid[row][col] == '1' && !Vis[row][col])
                {
                    cnt++;
                    bfs(row,col,Vis,grid,n,m);
                }
            }
        }
        return cnt;

    }
};