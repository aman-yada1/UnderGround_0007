// 38 ms | 36.3 MB
class Solution {
public:
    int sumCounts(vector<int>& nums) {
        long long sum = 0;
        set<int> s;

        for(int i=0;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
                s.insert(nums[j]);
                sum += pow(s.size(),2);
            }
            s.clear();
        }
        return sum;
    }
};