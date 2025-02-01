class Solution {
  public:
    bool FindMatch(vector<vector<char>>& mat, string& word,int row,int col,int wdx)
    {
        int n=mat.size();
        int m=mat[0].size();
        
        int Wordlen=word.size();
        
        if(wdx==Wordlen)
        {
            return true;
        }
        
        if(row<0 || col<0 || row>=n || col>=m)
        {
            return false;
        }
        
        if (mat[row][col] == word[wdx]) {

        // Marking this cell as visited
        char temp = mat[row][col];
        mat[row][col] = '#';

        // finding subpattern in 4 directions
        bool res = FindMatch(mat, word, row - 1, col, wdx + 1) ||
                   FindMatch(mat, word, row + 1, col, wdx + 1) ||
                   FindMatch(mat, word, row, col - 1, wdx + 1) ||
                   FindMatch(mat, word, row, col + 1, wdx + 1);

        // marking this cell as unvisited again
        mat[row][col] = temp;
        return res;
    }
    return false;
    }
    
    bool IsMatch(vector<vector<char>>& mat, string& word)
    {
        int n=mat.size();
        int m=mat[0].size();
        
        int Wordlen=word.size();
        if (Wordlen > n * m)
            return false;
            
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==word[0])
                {
                    if (FindMatch(mat,word,i,j,0))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    
    bool isWordExist(vector<vector<char>>& mat, string& word) 
    {
        return IsMatch(mat,word);
    }
};