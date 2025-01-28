//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void solve(string& s, int l, int r, set<string>& st){
        if(l==r) st.insert(s);
        else{
            for(int i=l;i<=r;i++){
                swap(s[i], s[l]);
                solve(s, l+1, r, st);
                swap(s[i], s[l]);
            }
        }
    }
    
    vector<string> findPermutation(string &s) {
        // Code here there
        set<string> st;
        solve(s, 0, s.size()-1, st);
        return {st.begin(), st.end()};
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends