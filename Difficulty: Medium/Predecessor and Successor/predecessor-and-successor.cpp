
/* BST Node
class Node
{
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        Node* pre = NULL, *suc = NULL;
        Node* curr = root;
        while (curr) {
            if (curr->data >= key)
                curr = curr->left;
            else {
                pre = curr;
                curr = curr->right;
            }
        }
        curr = root;
        while (curr) {
            if (curr->data <= key)
                curr = curr->right;
            else {
                suc = curr;
                curr = curr->left;
            }
        }
        return {pre, suc};
    }
};


