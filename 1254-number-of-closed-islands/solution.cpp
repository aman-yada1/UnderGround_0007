// 1 ms | 13.1 MB
class Solution {
public:
    bool dfs(int i, int j, vector<vector<int>>& grid, int n, int m){
        if (i < 0 || j < 0 || i >= n || j >= m) {
            return false;
        }

        if (grid[i][j] == 1) {
            return true;
        }
        grid[i][j] = 1;

        bool down = dfs(i + 1, j, grid, n, m);
        bool right = dfs(i, j + 1, grid, n, m);
        bool up = dfs(i - 1, j, grid, n, m);
        bool left = dfs(i, j - 1, grid, n, m);

        return down && right && up && left;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int island = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 0){
                    if(dfs(i,j,grid,n,m)){
                        island++;
                    }
                }
            }
        }
        return island;
    }
};