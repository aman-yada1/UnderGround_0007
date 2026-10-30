// 0 ms | 7.9 MB
class Solution {
public:
    string reverseOnlyLetters(string s) {
        int s1 = 0, e = s.size();
        while(s1 < e){
            if(isalpha(s[s1]) && isalpha(s[e])){
                swap(s[s1++],s[e--]);
            }
            else if(!isalpha(s[s1])){
                s1++;
            }
            else if(!isalpha(s[e])){
                e--;
            }
            else{
                s1++,e--;
            }
        }
        return s;
    }
};