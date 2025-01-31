class Solution {
  public:
  bool isSafe(vector<vector<int>> &mat,int row,int col,int num)
  {

    for (int x = 0; x <= 8; x++)
        if (mat[row][x] == num)
            return false;

   
    for (int x = 0; x <= 8; x++)
        if (mat[x][col] == num)
            return false;

    
    int startRow = row - (row % 3), startCol = col - (col % 3);

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (mat[i + startRow][j + startCol] == num)
                return false;

    return true;
  }
    bool solveSudokuRec(vector<vector<int>> &mat,int row,int col){
        int n = mat.size();

        if (row == n - 1 && col == n)
            return true;
    

        if (col == n) {
            row++;
            col = 0;
        }
    

        if (mat[row][col] != 0)
            return solveSudokuRec(mat, row, col + 1);
    
        for (int num = 1; num <= n; num++) {

            if (isSafe(mat, row, col, num)) {
                mat[row][col] = num;
                if (solveSudokuRec(mat, row, col + 1))
                    return true;
                mat[row][col] = 0;
            }
        }
      
          return false;
    }

    void solveSudoku(vector<vector<int>> &mat) {
        
         solveSudokuRec(mat, 0, 0);
    }
};