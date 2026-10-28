// 0 ms | 18.4 MB
class Solution {
public:
    void colorFill(int i, int j, vector<vector<int>>& image, int m, int n, int color, int start){
        if(i < 0 || j < 0 || i >= m || j >= n || image[i][j] != start || image[i][j] == color){
            return;
        }
        image[i][j] = color;

        colorFill(i+1,j,image,m,n,color,start);
        colorFill(i,j+1,image,m,n,color,start);
        colorFill(i-1,j,image,m,n,color,start);
        colorFill(i,j-1,image,m,n,color,start);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int start = image[sr][sc];

        colorFill(sr,sc,image,m,n,color,start);

        return image;
    }
};