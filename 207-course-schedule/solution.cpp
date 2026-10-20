// 61 ms | 17.8 MB
class Solution {
public:
    bool isCycle(int src, vector<bool>& vis, vector<bool>& recpath, vector<vector<int>>& edges){
        vis[src] = true;
        recpath[src] = true;

        for(int i=0;i<edges.size();i++){
            int v = edges[i][0];
            int u = edges[i][1];

            if(u == src){
                if(!vis[v]){
                    if(isCycle(v,vis,recpath,edges)){
                        return true;
                    }
                }
                else if(recpath[v]){
                    return true;
                }
            }
        }
        recpath[src] = false;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<bool> vis(n,false);
        vector<bool> recpath(n,false);

        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(isCycle(i,vis,recpath,prerequisites)){
                    return false;
                }
            }
        }
        return true;
    }
};