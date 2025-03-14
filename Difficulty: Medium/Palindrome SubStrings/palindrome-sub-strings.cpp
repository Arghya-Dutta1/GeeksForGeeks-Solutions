//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int countPS(string &s) {
        // code here
        int c=0, n=s.size();
        for(int i=0;i<n*2-1;i++){
            int l=i/2, r=(i+1)/2;
            while(l>=0 && r<n && s[l]==s[r]){
                if(r-l>=1)    
                    c++;
                l--;
                r++;
            }
        }
        return c;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.countPS(s) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends