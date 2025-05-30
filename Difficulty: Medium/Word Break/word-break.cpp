//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool wordBreak(string &s, vector<string> &dictionary) {
        // code here
        int n = s.size();
        vector<int> dp(n+1, -1);
        set<string> st;
        for(auto z : dictionary){
            st.insert(z);
        }
        
        return fun(0, s, st, dp);
    }
     int fun(int i, string &s, set<string> &st, vector<int> &dp){
        if(i==s.size())
            return 1;
        if(dp[i] != -1)
            return dp[i];
        
        string temp = "";
        for(int j=i;j<s.size();j++){
            temp+=s[j];
            if(st.find(temp) != st.end()){
                if(fun(j+1, s, st, dp))
                    return dp[i]=1;
            }
        }
        return dp[i]=0;
    }
};


//{ Driver Code Starts.

vector<string> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    vector<string> res;
    while (ss >> str) {
        res.push_back(str);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        cin >> s;
        cin.ignore();
        vector<string> dictionary = inputLine();

        Solution ob;
        if (ob.wordBreak(s, dictionary)) {
            cout << "true\n";
        } else
            cout << "false\n";
        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends