// 268 ms | 24.8 MB
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
    int height(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int left = height(root->left);
        int right = height(root->right);

        return max(left,right) + 1;
    }
    int findBottomLeftValue(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        if (root->left == NULL && root->right == NULL) {
            return root->val;
        }
        int m = height(root->left);
        int n = height(root->right);

        if( m < n){
            return findBottomLeftValue(root->right);
        }
        else {
            return findBottomLeftValue(root->left);
        }
    }
};