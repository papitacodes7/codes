#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void dfs(int i, int j, vector<vector<bool>> &vis, vector<vector<char>>& grid, int n, int m) {
        // base condition
        if(i < 0 || j < 0 || i >= n || j >= m || vis[i][j] || grid[i][j] != '1') {
            return;
        }

        vis[i][j] = true;

        // explore 4 directions
        dfs(i-1, j, vis, grid, n, m); // top
        dfs(i, j+1, vis, grid, n, m); // right
        dfs(i+1, j, vis, grid, n, m); // bottom
        dfs(i, j-1, vis, grid, n, m); // left
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        int islands = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '1' && !vis[i][j]) {
                    islands++;
                    dfs(i, j, vis, grid, n, m);
                }
            }
        }

        return islands;
    }
};

int main() {
    Solution obj;

    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    cout << "Number of Islands: " << obj.numIslands(grid);

    return 0;
}

//https://youtu.be/AME6baBpswY?si=Y1Ju4HA7kFwg_kRd watch pending.

//We traverse the whole grid using two loops. Whenever we encounter a cell with '1' and it is not visited, it means we have found a new island. So we increment the island count and start a DFS from that cell.

// The DFS will go in all 4 directions (top, right, bottom, left) and mark all connected '1' cells as visited, effectively covering the entire island in one go.

// This ensures that every island is counted exactly once because once a cell is visited, we never process it again.

// Since we visit each cell only once, the time complexity is O(n × m), and we use a visited matrix along with recursion stack, so space complexity is also O(n × m) in the worst case.