// 2 ms | 94.4 MB
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
    int ans = 0;
    void Zigzag(TreeNode* root,int left, int right){
        if (root == NULL) {
            return;
        }

        ans = max(ans, max(left, right));

        if (root->left) {
            Zigzag(root->left, right + 1, 0);
        }

        if (root->right) {
            Zigzag(root->right, 0, left + 1);
        }

    }
    int longestZigZag(TreeNode* root) {
        ans = 0;
        Zigzag(root,0,0);

        return ans;
    }
};