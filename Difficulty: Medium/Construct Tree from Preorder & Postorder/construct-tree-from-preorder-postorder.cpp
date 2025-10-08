/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    int preIndex = 0;
    
    Node* construct(vector<int> &pre, vector<int> &post, int start, int end, int n) {
        if (preIndex >= n || start > end)
            return NULL;
        Node* root = new Node(pre[preIndex++]);
        if (start == end || preIndex >= n)
            return root;
        int i;
        for (i = start; i <= end; i++) {
            if (post[i] == pre[preIndex])
                break;
        }
        
        if (i <= end) {
            root->left = construct(pre, post, start, i, n);
            root->right = construct(pre, post, i + 1, end - 1, n);
        }
        
        return root;
    }
    
    Node* constructTree(vector<int> &pre, vector<int> &post) {
        int n = pre.size();
        preIndex = 0;
        return construct(pre, post, 0, n - 1, n);
    }
};
