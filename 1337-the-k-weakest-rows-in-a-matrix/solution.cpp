// 0 ms | 14.2 MB
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();

        vector<pair<int, int>> ans;

        for (int i = 0; i < m; i++) {
            int sum = 0;

            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    sum++;
                }
            }

            ans.push_back({sum, i});
        }

        sort(ans.begin(), ans.end());

        vector<int> arr;

        for (int i = 0; i < k; i++) {
            arr.push_back(ans[i].second);
        }
        return arr;
    }
};