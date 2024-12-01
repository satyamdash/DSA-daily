class Solution {
public:
    bool Checkfill(int row,int col,vector<string>&board,int n)
    {
        int duprow=row;
        int dupcol=col;

        while(row>=0 && col>=0)
        {
            if(board[row][col]=='Q') return false;
            row--;
            col--;
        }

         row=duprow;
         col=dupcol;

        while(col>=0)
        {
            if(board[row][col]=='Q') return false;
            col--;
        }

         row=duprow;
         col=dupcol;

        while(row<n && col>=0)
        {
            if(board[row][col]=='Q') return false;
            row++;
            col--;
        }

        return true;
    }
    void FillQueen(int col,int n,vector<string>&board,vector<vector<string>>&Ans)
    {
        if(col==n)
        {
            Ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(Checkfill(row,col,board,n))
            {
                board[row][col]='Q';
                FillQueen(col+1,n,board,Ans);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>>Ans;
        vector<string>board(n);

        string s(n,'.');

        for(int i=0;i<n;i++)
        {
            board[i]=s;
        }
        FillQueen(0,n,board,Ans);
        return Ans;
    }
};