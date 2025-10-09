/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> postOrder(Node* root) {
        vector<int> post;
        if (!root)
            return post;
        
        stack<Node*> st1, st2;
        st1.push(root);
        
        while (!st1.empty()) {
            Node* curr = st1.top();
            st1.pop();
            st2.push(curr);
            
            if (curr->left)
                st1.push(curr->left);
            if (curr->right)
                st1.push(curr->right);
        }
        
        while (!st2.empty()) {
            post.push_back(st2.top()->data);
            st2.pop();
        }
        
        return post;
    }
};
