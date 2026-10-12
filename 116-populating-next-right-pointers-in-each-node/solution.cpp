// 15 ms | 19.2 MB
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL || root->left == NULL){
            return root;
        }
        queue<Node*> q;
        q.push(root);
        q.push(NULL);

        Node* pre = NULL;

        while(!q.empty()){
            Node* curr = q.front();
            q.pop();

            if(curr == NULL){

                if(q.size() == 0){
                    break;
                }
                q.push(NULL);
            }
            else{
                if(curr->left != NULL){
                    q.push(curr->left);
                }
                if(curr->right != NULL){
                    q.push(curr->right);
                }
                if(pre != NULL){
                    pre->next = curr;
                }
            }
            pre = curr;
        }
        return root;
    }
};