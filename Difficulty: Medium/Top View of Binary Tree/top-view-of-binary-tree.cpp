/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        if(!root)
            return {};
        vector<int> ans;
        map<int, int> mp;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                Node* curr=q.front().first;
                int idx=q.front().second;
                q.pop();
                if(curr->left)
                    q.push({curr->left, idx-1});
                if(curr->right)
                    q.push({curr->right, idx+1});
                if(!mp.count(idx))
                    mp[idx]=curr->data;
            }
        }
        for(auto it:mp)
            ans.push_back(it.second);
        return ans;
    }

};



