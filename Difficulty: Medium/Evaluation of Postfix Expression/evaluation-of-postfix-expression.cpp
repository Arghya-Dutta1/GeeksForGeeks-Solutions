//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int evaluate(vector<string>& arr) {
        // code here
        stack<int> st;
        for(auto& i:arr)
            if(isdigit(i[0]) || (i.size()>1 && i[0]=='-'))
                st.push(stoi(i));
            else{
                int t=0, f=st.top();
                st.pop();
                int s=st.top();
                st.pop();
                switch(i[0]){
                    case '+':
                        t=s+f;
                        break;
                    case '-':
                        t=s-f;
                        break;
                    case '*':
                        t=s*f;
                        break;
                    case '/':
                        t=s/f;
                }
                st.push(t);
            }
        return st.top();
    }
};


//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<string> arr;
        while (ss >> str) {
            arr.push_back(str);
        }
        Solution ob;
        cout << ob.evaluate(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends