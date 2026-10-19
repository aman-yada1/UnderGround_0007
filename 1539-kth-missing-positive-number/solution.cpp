// 0 ms | 13.3 MB
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size() + k;
        int m = 0;

        for(int i=1;i<=n;i++){
            if(m < arr.size() && i == arr[m]){
                m++;
            }else{
                k--;
                if(k == 0){
                    return i;
                }
            }
        }
        return 0;
    }
};