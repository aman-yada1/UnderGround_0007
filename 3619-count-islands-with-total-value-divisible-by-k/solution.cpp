// 201 ms | 201.5 MB
class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        int island = 0;

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] > 0 && !vis[i][j]) {
                    long long sum = 0;
                    stack<pair<int, int>> st;

                    st.push({i, j});
                    vis[i][j] = true;

                    while (!st.empty()) {
                        auto [x, y] = st.top();
                        st.pop();

                        sum += grid[x][y];

                        for (int d = 0; d < 4; d++) {
                            int nx = x + dx[d];
                            int ny = y + dy[d];

                            if (nx >= 0 && nx < n &&
                                ny >= 0 && ny < m &&
                                grid[nx][ny] > 0 &&
                                !vis[nx][ny]) {

                                vis[nx][ny] = true;
                                st.push({nx, ny});
                            }
                        }
                    }

                    if (sum % k == 0) {
                        island++;
                    }
                }
            }
        }
        return island;
    }
};