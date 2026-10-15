// 0 ms | 24.4 MB
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
    void inorder(TreeNode* root){
        if(root != NULL){
            inorder(root->left);
            ans.push_back(root->val);
            inorder(root->right);
        }
    }
    vector<int> findMode(TreeNode* root) {
        ans.clear();
        inorder(root);

        vector<int> a;
        int maxi = 0;

        for (int i = 0; i < ans.size();) {
            int count = 1;

            while (i + count < ans.size() &&
                   ans[i] == ans[i + count]) {
                count++;
            }

            if (count > maxi) {
                maxi = count;
                a.clear();
                a.push_back(ans[i]);
            }
            else if (count == maxi) {
                a.push_back(ans[i]);
            }

            i += count;
        }
        return a;
    }
};