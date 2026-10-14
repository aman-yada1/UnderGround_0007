// 13 ms | 16.4 MB
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        vector<int> a;

        if(root == NULL){
            return ans;
        }

        queue<Node*> q;
        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            Node* curr = q.front();
            q.pop();

            if(curr == NULL){
                ans.push_back(a);
                a.clear();

                if(!q.empty()){
                    q.push(NULL);
                }
                continue;
            }
            a.push_back(curr->val);

            for(auto n : curr->children){
                q.push(n);
            }
        }
        return ans;
    }
};