// 0 ms | 17.6 MB
class Solution {
public:
    int finalValueAfterOperations(vector<string>& n) {
        int ans = 0;

        for(string s : n){
            if(s == "--X"){
                --ans;
            }
            else if(s == "++X"){
                ++ans;
            }
            else if(s == "X--"){
                ans--;
            }
            else{
                ans++;
            }
        }
        return ans;
    }
};