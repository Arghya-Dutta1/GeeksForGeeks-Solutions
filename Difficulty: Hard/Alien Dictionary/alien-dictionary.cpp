//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string findOrder(vector<string> &A) {
        // code here
        unordered_map<int, unordered_set<int>> G;
        int indegree[26] = {};
        for (auto &s : A) {
            for (char c : s) G[c - 'a'] = {};
        }
        for (int i = 1; i < A.size(); ++i) {
            int j = 0;
            for (; j < min(A[i - 1].size(), A[i].size()); ++j) {
                if (A[i - 1][j] == A[i][j]) continue;
                G[A[i - 1][j] - 'a'].insert(A[i][j] - 'a');
                break;
            }
            if (j == A[i].size() && j < A[i - 1].size()) return "";
        }
        for (auto &i : G) {
            for (int to : i.second) {
                indegree[to]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < 26; ++i) {
            if (G.count(i) && indegree[i] == 0) q.push(i);
        }
        string ans;
        while (q.size()) {
            int u = q.front();
            q.pop();
            ans += u + 'a';
            for (int v : G[u]) {
                if (--indegree[v] == 0) q.push(v);
            }
        }
        return ans.size() == G.size() ? ans : "";
    }
};


//{ Driver Code Starts.

bool validate(const vector<string> &original, const string &order) {
    unordered_map<char, int> mp;
    for (const string &word : original) {
        for (const char &ch : word) {
            mp[ch] = 1;
        }
    }
    for (const char &ch : order) {
        if (mp.find(ch) == mp.end())
            return false;
        mp.erase(ch);
    }
    if (!mp.empty())
        return false;

    for (int i = 0; i < order.size(); i++) {
        mp[order[i]] = i;
    }

    for (int i = 0; i < original.size() - 1; i++) {
        const string &a = original[i];
        const string &b = original[i + 1];
        int k = 0, n = a.size(), m = b.size();
        while (k < n and k < m and a[k] == b[k]) {
            k++;
        }
        if (k < n and k < m and mp[a[k]] > mp[b[k]]) {
            return false;
        }
        if (k != n and k == m) {
            return false;
        }
    }
    return true;
}

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        string curr;
        vector<string> words;
        while (ss >> curr)
            words.push_back(curr);

        vector<string> original = words;

        Solution ob;
        string order = ob.findOrder(words);

        if (order.empty()) {
            cout << "\"\"" << endl;
        } else {
            cout << (validate(original, order) ? "true" : "false") << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends