// 456 ms | 220.2 MB
class Solution {
    using ll = long long;

    class Fenwick {
    public:
        int n;
        vector<ll> bit;

        Fenwick(int n) : n(n), bit(n + 1, 0) {}

        void update(int i, ll val) {
            for (; i <= n; i += i & -i)
                bit[i] += val;
        }

        ll query(int i) {
            ll sum = 0;
            for (; i > 0; i -= i & -i)
                sum += bit[i];
            return sum;
        }

        int kth(ll k) {
            int idx = 0;
            int step = 1;

            while (step * 2 <= n)
                step *= 2;

            for (; step; step >>= 1) {
                int next = idx + step;

                if (next <= n && bit[next] < k) {
                    idx = next;
                    k -= bit[next];
                }
            }

            return idx + 1;
        }
    };

public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        vector<int> vals = nums;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        int m = vals.size();

        vector<int> rank(n);

        for (int i = 0; i < n; i++) {
            rank[i] = lower_bound(vals.begin(), vals.end(), nums[i])  - vals.begin() + 1;
        }

        Fenwick cnt(m), sum(m);

        auto add = [&](int r, int v) {
            cnt.update(r, 1);
            sum.update(r, v);
        };

        auto remove = [&](int r, int v) {
            cnt.update(r, -1);
            sum.update(r, -v);
        };

        auto getCost = [&]() -> ll {
            int medRank = cnt.kth((x + 1) / 2);
            ll median = vals[medRank - 1];

            ll leftCount = cnt.query(medRank);
            ll leftSum = sum.query(medRank);

            ll totalSum = sum.query(m);
            ll totalCount = x;

            ll rightCount = totalCount - leftCount;
            ll rightSum = totalSum - leftSum;

            return median * leftCount - leftSum + rightSum - median * rightCount;
        };

        vector<ll> cost(n - x + 1);

        for (int i = 0; i < x; i++)
            add(rank[i], nums[i]);

        cost[0] = getCost();

        for (int i = x; i < n; i++) {
            remove(rank[i - x], nums[i - x]);
            add(rank[i], nums[i]);

            cost[i - x + 1] = getCost();
        }

        const ll INF = 1e18;

        vector<ll> prev(n + 1, 0);
        vector<ll> curr(n + 1, INF);

        for (int j = 1; j <= k; j++) {
            fill(curr.begin(), curr.end(), INF);

            for (int i = 1; i <= n; i++) {
                curr[i] = curr[i - 1];

                if (i >= x) {
                    curr[i] = min(
                        curr[i],
                        prev[i - x] + cost[i - x]
                    );
                }
            }

            prev.swap(curr);
        }
        return prev[n];
    }
};