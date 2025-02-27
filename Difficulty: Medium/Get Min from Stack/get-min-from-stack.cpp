//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    stack<int> st, mn;

    // Add an element to the top of Stack
    void push(int x) {
        // code here
        st.push(x);
        if(mn.empty()||x<=mn.top())
            mn.push(x);
    }

    // Remove the top element from the Stack
    void pop() {
        // code here
        if(st.empty()) return;
        if(st.top()==mn.top()) mn.pop();
        st.pop();
    }

    // Returns top element of the Stack
    int peek() {
        // code here
        return st.empty()?-1:st.top();
    }

    // Finds minimum element of Stack
    int getMin() {
        // code here
        return mn.empty()?-1:mn.top();
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> q;

        Solution ob;

        while (q--) {
            int qt;
            cin >> qt;

            if (qt == 1) {
                // push
                int att;
                cin >> att;
                ob.push(att);
            } else if (qt == 2) {
                // pop
                ob.pop();
            } else if (qt == 3) {
                // peek
                cout << ob.peek() << " ";
            } else if (qt == 4) {
                // getMin
                cout << ob.getMin() << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends