//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    char pop(stack<char>& s){
        char c=s.top();
        s.pop();
        return c;
    }
  
    bool isBalanced(string& s) {
        // code here
        stack<char> st;
        for(char i:s){
            if(i == '(')
                st.push(')');
            else if(i == '{')
                st.push('}');
            else if(i == '[')
                st.push(']');
            else if(st.empty() || pop(st)!=i)
                return false;
        }
        return st.empty();
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    string a;
    cin >> t;
    while (t--) {
        cin >> a;
        Solution obj;
        if (obj.isBalanced(a))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends