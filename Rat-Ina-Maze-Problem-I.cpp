class Solution {
  public:
    
    void fun(int row,int col,vector<vector<int>> &mat,int n,vector<string>&Ans,string &temp,vector<vector<bool>>&visited)
    {
        if(row==n-1 && col==n-1)
        {
            Ans.push_back(temp);
            return;
        }
        
        visited[row][col]=true;
        
        if(row+1<n && mat[row+1][col]==1 && !visited[row + 1][col])
        {
            temp.push_back('D');
            fun(row+1,col,mat,n,Ans,temp,visited);
            temp.pop_back();
        }
        if(col+1<n && mat[row][col+1]==1 && !visited[row][col+1])
        {
            temp.push_back('R');
            fun(row,col+1,mat,n,Ans,temp,visited);
            temp.pop_back();
        }
        
        if(row-1>=0 && mat[row-1][col]==1 && !visited[row-1][col])
        {
            temp.push_back('U');
            fun(row-1,col,mat,n,Ans,temp,visited);
            temp.pop_back();
        }
        
        if(col-1>=0 && mat[row][col-1]==1 && !visited[row][col-1])
        {
            temp.push_back('L');
            fun(row,col-1,mat,n,Ans,temp,visited);
            temp.pop_back();
        }
        visited[row][col] = false;
        
    }
    vector<string> findPath(vector<vector<int>> &mat) 
    {
        int n = mat.size();
    vector<string> Ans;
    vector<vector<bool>>visited(n,vector<bool>(n, false));
    string temp = "";
    
    // Ensure the starting point is valid
    if (mat[0][0] == 1) {
        fun(0, 0, mat, n, Ans, temp,visited);
    }
    return Ans;
    }
};