class Solution {
public:
    void DFS(int row,int col,vector<vector<int>>&Vis,vector<vector<char>>&board,int n,int m)
    {
        Vis[row][col]=1;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};

        for(int i=0;i<4;i++)
        {
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];

            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m &&
            board[nrow][ncol]=='O' &&!Vis[nrow][ncol])
            {
                DFS(nrow,ncol,Vis,board,n,m);
            }
        }
    }
    void solve(vector<vector<char>>& board) 
    {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>Vis(n,vector<int>(m,0));  

        //Boundary check
        //1st row
      for(int col=0;col<m;col++)
      {
        if(board[0][col]=='O')
        {
            DFS(0,col,Vis,board,n,m);
        }
      } 

    for(int row = 0; row < n; row++)  // Loop over rows instead of columns
    {
        if(board[row][0] == 'O')
        {
            DFS(row, 0, Vis, board, n, m);
        }
    }

     for(int col=0;col<m;col++)
      {
        if(board[n-1][col]=='O')
        {
            DFS(n-1,col,Vis,board,n,m);
        }
      }

    for(int row = 0; row < n; row++)  // Loop over rows instead of columns
    {
        if(board[row][m-1] == 'O')
        {
            DFS(row, m-1, Vis, board, n, m);
        }
    }

      for(int i=0;i<n;i++)
      {
        for(int j=0;j<m;j++)
        {
            if(Vis[i][j]==1)
            {
                board[i][j]='O';
            }
            else
            {
                board[i][j]='X';
            }
        }
      }
    }
};