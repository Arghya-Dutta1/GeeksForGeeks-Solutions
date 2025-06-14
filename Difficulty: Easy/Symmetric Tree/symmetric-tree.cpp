/*
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
class Solution {
  public:
    bool dfs(Node* r1, Node* r2){
        if(!r1 && !r2)
            return true;
        if(!r1 || !r2)
            return false;
        bool ans=1;
        if(r1->data==r2->data){
            ans &= dfs(r1->left, r2->right);
            ans &= dfs(r1->right, r2->left);
        }
        else
            ans=0;
        return ans;
    }
  
    bool isSymmetric(Node* root) {
        // Code here
        return dfs(root->left, root->right);
    }
};