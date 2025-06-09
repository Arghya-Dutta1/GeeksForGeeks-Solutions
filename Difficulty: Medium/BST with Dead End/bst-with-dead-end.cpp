/*The Node structure is
class Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};*/

class Solution {
  public:
    bool Inorder(Node* root,int mini,int maxi)
    {
        if(root!=nullptr)
        {
            
            if(root->left == nullptr and root->right==nullptr and mini==maxi) return true;
            return Inorder(root->left,mini,root->data-1) or Inorder(root->right,root->data+1,maxi);
        }
        return false;
    }
    
    bool isDeadEnd(Node *root) {
        return Inorder(root,1,INT_MAX);
    }
};