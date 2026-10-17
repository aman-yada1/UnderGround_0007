// 11 ms | 23.7 MB
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
    int sum(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int left = sum(root->left);
        int right = sum(root->right);

        return left + right + root->val;
    }
    int findTilt(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int left = sum(root->left);
        int right = sum(root->right);

        return findTilt(root->left) + findTilt(root->right) + abs(left - right);
    }
};