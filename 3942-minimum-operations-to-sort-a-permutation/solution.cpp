// 6 ms | 141.3 MB
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        if (is_sorted(nums.begin(), nums.end())) {
            return 0;
        }

        int pos = find(nums.begin(), nums.end(), 0) - nums.begin();

        // Case 1: Check ascending circular order
        bool asc = true;

        for (int i = 0; i < n; i++) {
            if (nums[(pos + i) % n] != i) {
                asc = false;
                break;
            }
        }

        int ans = INT_MAX;

        if (asc) {
            ans = min(pos, n - pos + 2);
        }

        // Case 2: Check descending circular order
        bool desc = true;

        for (int i = 0; i < n; i++) {
            if (nums[(pos - i + n) % n] != i) {
                desc = false;
                break;
            }
        }

        if (desc) {
            int k = (n - 1 - pos + n) % n;
            ans = min(ans, min(k + 1, n - k + 1));
        }

        return ans == INT_MAX ? -1 : ans;
    }
};