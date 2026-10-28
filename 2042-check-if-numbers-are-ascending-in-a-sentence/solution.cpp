// 0 ms | 8.5 MB
class Solution {
public:
    bool areNumbersAscending(string s) {
        vector<int> ans;

        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                int num = 0;

            while (i < s.size() && isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                i++;
            }

            ans.push_back(num);
            }
        }
        return (is_sorted(ans.begin(),ans.end()) && adjacent_find(ans.begin(), ans.end()) == ans.end());
    }
};