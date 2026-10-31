// 1 ms | 8.4 MB
class Solution {
public:
    bool digitCount(string num) {
        unordered_map<char,int> mp;

        for(char ch: num){
            mp[ch]++;
        }
        for(int i=0;i<num.size();i++){
            if((num[i]-'0') != mp['0' + i]){
                return false;
            }
        }
        return true;
    }
};