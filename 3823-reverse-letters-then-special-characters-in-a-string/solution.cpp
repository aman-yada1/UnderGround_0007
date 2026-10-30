// 0 ms | 8.6 MB
class Solution {
public:
    string reverseByType(string s) {
        int s1 = 0, e = s.size()-1;

        while(s1 < e){
            if(isalnum(s[s1]) && isalnum(s[e])){
                swap(s[s1++],s[e--]);
            }
            else if(!isalnum(s[s1])){
                s1++;
            }
            else if(!isalnum(s[e])){
                e--;
            }
            else{
                s1++,e--;
            }
        }

        s1 = 0, e = s.size()-1;

        while(s1 < e){
            if(!isalnum(s[s1]) && !isalnum(s[e])){
                swap(s[s1++],s[e--]);
            }
            else if(isalnum(s[s1])){
                s1++;
            }
            else if(isalnum(s[e])){
                e--;
            }
            else{
                s1++,e--;
            }
        }
        return s;
    }
};