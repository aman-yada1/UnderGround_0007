// 1 ms | 22.6 MB
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
    vector<int> ans;
    vector<int> levelorder(TreeNode* root){
        if(root == NULL){
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> a;

        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();

            if(curr == NULL){
                int m = *max_element(a.begin(),a.end());
                ans.push_back(m);
                a.clear();

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
        return ans;
    }

    vector<int> largestValues(TreeNode* root) {
        return levelorder(root);
    }
};