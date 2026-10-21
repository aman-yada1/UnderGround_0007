// 0 ms | 15.1 MB
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
    bool checkTree(TreeNode* root) {
        if(root == NULL){
            return false;
        }
        int m;
        if(root->left != NULL && root->right != NULL){
            m = root->left->val + root->right->val;;
        }
        if(root->right != NULL && root->left == NULL){
            m = root->right->val;
        }
        if(root->right == NULL && root->left != NULL){
            m = root->left->val;
        }

        if(m == root->val){
            return true;
        }

        return checkTree(root->left) || checkTree(root->right);
    }
};