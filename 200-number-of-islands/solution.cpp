// 28 ms | 16.7 MB
class Solution {
public:
    void dfs(int i,int j, vector<vector<bool>>& vis,vector<vector<char>>& grid, int n, int m){
        if(i < 0 || j < 0 || i >= n || j >= m || vis[i][j] || grid[i][j] != '1'){
            return;
        }
        vis[i][j] = true;

        dfs(i+1,j,vis,grid,n,m);
        dfs(i,j+1,vis,grid,n,m);
        dfs(i-1,j,vis,grid,n,m);
        dfs(i,j-1,vis,grid,n,m);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> v(n,vector<bool> (m,false));
        int island = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1' && !v[i][j]){
                    dfs(i,j,v,grid,n,m);
                    island++;
                }
            }
        }
        return island;
    }
};