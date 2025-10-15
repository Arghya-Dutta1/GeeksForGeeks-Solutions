/*Complete the function below

struct Node {
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
    // Return the Kth smallest element in the given BST
    void inorder(Node* root, int k, int& ans, int& rank){
        if(!root) return;
        inorder(root->left, k, ans, rank);
        if(++rank==k){
            ans=root->data;
            return;
        }
        inorder(root->right, k, ans, rank);
    }
    
    int kthSmallest(Node *root, int k) {
        // add code here.
        int ans=-1, rank=0;
        inorder(root, k, ans, rank);
        return ans;
    }
};
