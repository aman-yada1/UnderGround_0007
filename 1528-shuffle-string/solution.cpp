// 2 ms | 19.2 MB
class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        vector<pair<int, char>> v;
        for(int i=0;i<s.size();i++){
            v.push_back({indices[i],s[i]});
        }

        sort(v.begin(),v.end());

        s.clear();
        for(auto p:v){
            s.push_back(p.second);
        }

        return s;
    }
};