// 5 ms | 16.1 MB
class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        map<int,int> mp;
        for(int x: nums){
            mp[x]++;
        }
        vector<int> ans;
        for(auto v : mp){
            while(v.second--){
                ans.push_back(v.first);
            }
        }
        vector<int> a;
        for(int i=0;i<ans.size();i++){
            if(ans[i] == target){
                a.push_back(i);
            }
        }
        return a;
    }
};