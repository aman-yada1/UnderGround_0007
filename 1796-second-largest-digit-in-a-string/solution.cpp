// 0 ms | 9.6 MB
class Solution {
public:
    int secondHighest(string s) {
        set<int> s1;

        for(char ch : s){
            if(isdigit(ch)){
                s1.insert(ch - '0');
            }
        }
        if(s1.size() >= 2){
            auto it = s1.rbegin(); ++it; 
            return *it; 
        }
        return -1;
    }
};