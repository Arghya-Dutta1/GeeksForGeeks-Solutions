//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++
class Trie {
    private:
    vector<Trie*> children;
    bool isEnd;

    Trie* searchPrefix(string pre){
        Trie* node=this;
        for(auto i:pre){
            int idx=i-'a';
            if(!node->children[idx]) return NULL;
            node=node->children[idx];
        }
        return node;
    }
  public:
    Trie(): children(26, NULL), isEnd(false) {}
    
    void insert(string word) {
        Trie* node=this;
        for(auto i:word){
            int idx=i-'a';
            if(!node->children[idx]) node->children[idx]=new Trie();
            node=node->children[idx];
        }
        node->isEnd=true;
    }
    
    bool search(string word) {
        Trie* node=searchPrefix(word);
        return node && node->isEnd;
    }
    
    bool isPrefix(string prefix) {
        Trie* node=searchPrefix(prefix);
        return node;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int q;
        cin >> q;
        cin.ignore();
        vector<bool> ans;
        Trie ob;
        for (int i = 0; i < q; i++) {
            int x;
            cin >> x;
            string s;
            cin >> s;
            cin.ignore();
            if (x == 1) {
                ob.insert(s);
            } else if (x == 2) {
                ans.push_back(ob.search(s));
            } else if (x == 3) {
                ans.push_back(ob.isPrefix(s));
            }
        }
        cout << boolalpha;
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends