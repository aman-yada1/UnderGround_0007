// 67 ms | 212.2 MB
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<long long> ans;

        for(int x: nums){
            ans.push_back(1LL * x * x);
        }
        sort(ans.begin(),ans.end());

        long long sum = 0;
        int n = ans.size();

        for (int i = 0; i < n; i++) {
            if (i < (n + 1) / 2) {
                sum += ans[n - 1 - i];
            } else {
                sum -= ans[n - 1 - i];
            }
        }
        return sum;
    }
};