// 7 ms | 12.7 MB
class Solution {
public:
    bool canConstruct(string r, string m) {
        unordered_map<char,int> mp;

        for(char c : m){
            mp[c]++;
        }
        for(char c : r){
            if(mp[c] == 0){
                return false;
            }
            mp[c]--;
        }
        return true;
    }
};