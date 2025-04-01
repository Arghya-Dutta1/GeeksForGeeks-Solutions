//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<bool> vis(adj.size()+1, false);
        vector<int> ans;
        stack<int> st;
        st.push(0);
        while(!st.empty()){
            int i=st.top();
            st.pop();
            if(!vis[i]){
                ans.push_back(i);
                vis[i]=true;
            }
            for(auto it=adj[i].rbegin(); it!=adj[i].rend(); it++)
                if(!vis[*it])
                    st.push(*it);
        }
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V;
        cin >> V;
        cin.ignore();
        vector<vector<int>> adj(
            V); // Use vector of vectors instead of array of vectors.

        for (int i = 0; i < V; i++) {
            string input;
            getline(cin, input);
            int num;
            vector<int> node;
            stringstream ss(input);
            while (ss >> num) {
                node.push_back(num);
            }
            adj[i] = node;
        }

        Solution obj;
        vector<int> ans = obj.dfs(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends