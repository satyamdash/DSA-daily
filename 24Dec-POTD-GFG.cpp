class Solution {
  public:
    // Function to search a given number in row-column sorted matrix.
    bool searchMatrix(vector<vector<int>> &mat, int x) 
    {
       int n = mat.size();
        int m = mat[0].size();

        int low = 0, high = n * m - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            int midVal = mat[mid / m][mid % m];

            if (midVal == x) {
                return true;
            } else if (midVal > x) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return false;
    }
};