// User Fuction template for C++
/*
// Tree Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
  
    int ans=INT_MIN;

    void pre(Node* root){
        if(!root)
            return;
        pre(root->left);
        int d=depthSum(root);
        pre(root->right);
    }
  
    int depthSum(Node* root){
        if(!root)
            return 0;
        int ls=max(0, depthSum(root->left));
        int rs=max(0, depthSum(root->right));
        ans = max(ans, ls+rs+root->data);
        return max(ls,rs)+root->data;
    }
  
    // Function to return maximum path sum from any node in a tree.
    int findMaxSum(Node *root) {
        // code here
        pre(root);
        return ans;
    }
};
