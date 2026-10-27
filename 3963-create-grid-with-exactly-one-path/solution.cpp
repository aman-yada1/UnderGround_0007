// 2 ms | 10.9 MB
class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans(m, string(n, '#'));
        int i=0, j=0;

        while (i < m && j < n) {
            ans[i][j] = '.';

            if (j + 1 < n) {
                j++;
            } else {
                i++;
            }
        }

        return ans;
    }
};