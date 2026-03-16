/*
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
    int countAllPaths(Node *root, int k) {
        // code here
        unordered_map<long, int> mp;
        mp[0]=1;

        function<int(Node*, long)> dfs=[&](Node* node, long s)->int {
            if(!node) return 0;
            s+=node->data;
            int ans=mp[s-k];
            mp[s]++;
            ans+=dfs(node->left, s)+dfs(node->right, s);
            mp[s]--;
            return ans;
        };

        return dfs(root, 0);
    }
};
