// 382 ms | 167.7 MB
class Solution {
public:
    int sumCounts(vector<int>& nums) {
        const long long MOD = 1000000007;
        int n = nums.size();

        vector<long long> seg(4 * n, 0);
        vector<long long> lazy(4 * n, 0);

        long long ans = 0;
        long long sum = 0;

        auto update = [&](auto&& self, int node, int start, int end,
                          int l, int r, long long val) -> void {
            if (l > end || r < start) return;

            if (l <= start && end <= r) {
                sum += 0; // No operation needed here
                long long len = end - start + 1;
                lazy[node] += val;
                seg[node] = (seg[node] + 2 * val * 0) % MOD;
                return;
            }
        };

        // Use a segment tree that maintains both sum and sum of squares.
        vector<long long> sq(4 * n, 0);
        vector<long long> add(4 * n, 0);

        auto build = [&](auto&& self, int node, int l, int r) -> void {
            if (l == r) {
                seg[node] = 0;
                sq[node] = 0;
                return;
            }
            int mid = (l + r) / 2;
            self(self, node * 2, l, mid);
            self(self, node * 2 + 1, mid + 1, r);
        };

        auto apply = [&](int node, int l, int r, long long val) {
            long long len = r - l + 1;
            sq[node] = (sq[node] + 2 * val % MOD * seg[node] % MOD
                        + len % MOD * val % MOD * val % MOD) % MOD;
            seg[node] = (seg[node] + len * val) % MOD;
            add[node] = (add[node] + val) % MOD;
        };

        auto push = [&](int node, int l, int r) {
            if (add[node] == 0 || l == r) return;
            int mid = (l + r) / 2;
            apply(node * 2, l, mid, add[node]);
            apply(node * 2 + 1, mid + 1, r, add[node]);
            add[node] = 0;
        };

        auto rangeUpdate = [&](auto&& self, int node, int l, int r,
                               int ql, int qr, long long val) -> void {
            if (ql > r || qr < l) return;

            if (ql <= l && r <= qr) {
                apply(node, l, r, val);
                return;
            }

            push(node, l, r);
            int mid = (l + r) / 2;

            self(self, node * 2, l, mid, ql, qr, val);
            self(self, node * 2 + 1, mid + 1, r, ql, qr, val);

            seg[node] = (seg[node * 2] + seg[node * 2 + 1]) % MOD;
            sq[node] = (sq[node * 2] + sq[node * 2 + 1]) % MOD;
        };

        unordered_map<int, int> last;

        for (int i = 0; i < n; i++) {
            int left = last.count(nums[i]) ? last[nums[i]] + 1 : 0;

            rangeUpdate(rangeUpdate, 1, 0, n - 1, left, i, 1);

            ans = (ans + sq[1]) % MOD;
            last[nums[i]] = i;
        }
        return (int)ans;
    }
};