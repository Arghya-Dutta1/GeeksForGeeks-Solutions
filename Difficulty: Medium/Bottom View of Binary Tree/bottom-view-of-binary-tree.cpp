//Function to return a list containing the bottom view of the given tree.

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int> ans;
        queue<pair<Node*, int>> q;
        map<int, int> mp;
        q.push({root, 0});
        while(q.size()>0){
            int s=q.size();
            for(int i=0;i<s;i++){
                Node* N = q.front().first;
                int ind = q.front().second;
                q.pop();
                if(N->left) q.push({N->left, ind-1});
                if(N->right) q.push({N->right, ind+1});
                //if(mp.find(ind)==mp.end())
                    mp[ind]=N->data;
            }
        }
        for(auto i:mp)
            ans.push_back(i.second);
        return ans;
    }
};
