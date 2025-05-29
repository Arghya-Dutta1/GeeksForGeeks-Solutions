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
}; */

class Solution {
  public:
    void dfs(Node* node, int currentLength, int currentSum, int& maxLength, int& maxSum) {
        if (node == NULL) return;
        currentSum += node->data;
        currentLength++;

        if (node->left == NULL && node->right == NULL) {
            if (currentLength > maxLength) {
                maxLength = currentLength;
                maxSum = currentSum;
            } 
            else if (currentLength == maxLength)
                maxSum = max(maxSum, currentSum);
            return;
        }

        dfs(node->left, currentLength, currentSum, maxLength, maxSum);
        dfs(node->right, currentLength, currentSum, maxLength, maxSum);
    }

    int sumOfLongRootToLeafPath(Node *root) {
        int maxLength = 0, maxSum = 0;
        dfs(root, 0, 0, maxLength, maxSum);
        return maxSum;
    }
};
