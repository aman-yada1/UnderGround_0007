// 1 ms | 24 MB
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
    vector<double> ans;
    void levelorder(TreeNode* root){
        vector<int> a;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();

            if(curr == NULL){
                double sum = 0;
                for(int x : a){
                    sum += x;
                }
                ans.push_back(sum/a.size());
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
    }
    vector<double> averageOfLevels(TreeNode* root) {
        levelorder(root);
        return ans;
    }
};