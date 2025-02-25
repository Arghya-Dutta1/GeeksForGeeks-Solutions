//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int getMaxArea(vector<int> &ht) {
        // Your code here
        int n=ht.size(), ans=0;
        stack<vector<int>> st;
        vector<int> left(n, -1), right(n, n);

        st.push({-1,-1});
        
        for(int i=0;i<n;i++){
            while(!st.empty() && st.top()[0]>=ht[i])
                st.pop();
            left[i]=st.top()[1];
            st.push({ht[i], i});
        }

        while(!st.empty()) st.pop();
        st.push({-1,n});

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()[0]>=ht[i])
                st.pop();
            right[i]=st.top()[1];
            st.push({ht[i], i});
        }

        for(int i=0;i<n;i++)
            ans=max(ans, ht[i]*(right[i]-left[i]-1));
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends