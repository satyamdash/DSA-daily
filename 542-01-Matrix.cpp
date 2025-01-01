#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> Vis(n, vector<int>(m, 0));
        vector<vector<int>> Dist(n, vector<int>(m, -1)); // Initialize with -1 for unvisited cells
        queue<pair<int, int>> q;

        // Add all cells with 0 to the queue and mark them as visited
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    Vis[i][j] = 1; // Mark as visited
                    Dist[i][j] = 0; // Distance to nearest 0 is 0
                }
            }
        }

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        // Perform BFS to calculate minimum distance
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && Vis[nrow][ncol] == 0) {
                    Vis[nrow][ncol] = 1; // Mark as visited
                    Dist[nrow][ncol] = Dist[row][col] + 1; // Set the distance
                    q.push({nrow, ncol}); // Add the new position to the queue
                }
            }
        }

        return Dist;
    }
};