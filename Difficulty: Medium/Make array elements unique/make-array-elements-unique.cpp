//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minIncrements(vector<int> arr) {
        // Code here
        int n=arr.size(), c=0, mx=*max_element(arr.begin(), arr.end());
        vector<int> f(n+mx, 0);
        for(int i:arr){
            f[i]++;
        }
        for(int i=0;i<f.size();i++){
            if(f[i]>1){
                f[i+1]+=f[i]-1;
                c+=f[i]-1;
                f[i]=1;
            }
        }
        return c;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        int ans = ob.minIncrements(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends