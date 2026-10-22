// 1 ms | 15.2 MB
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> ans;
    void levelOrder(TreeNode* root){
        if(root == NULL){
            return;
        }
        vector<int> a;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        bool leftToRight = true;

        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();

            if(curr == NULL){
                if(!a.empty()){
                    if(!leftToRight){
                        reverse(a.begin(),a.end());
                    }
                    ans.push_back(a);
                    a.clear();
                    leftToRight = !leftToRight;
                }
                if(!q.empty()){
                    q.push(NULL);
                }
                continue;
            }
            a.push_back(curr->val);

            if(curr->left != NULL){
                q.push(curr->left);
            }
            if(curr->right != NULL){
                q.push(curr->right);
            }

        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        levelOrder(root);

        return ans;
    }
};