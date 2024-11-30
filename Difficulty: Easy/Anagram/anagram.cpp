//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function is to check whether two strings are anagram of each other or not.
    bool areAnagrams(string& s1, string& s2) {
        // Your code here
        map<int, int> mp1, mp2;
        for(auto c:s1) mp1[c]++;
        for(auto c:s2) mp2[c]++;
        if(mp1.size()!=mp2.size()) return false;
        
        auto i1=mp1.begin(), i2=mp2.begin();
        while(i1!=mp1.end() && i2!=mp2.end()){
            if((*i1).first!=(*i2).first || (*i1).second!=(*i2).second) return false;
            i1++;
            i2++;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {
        string c, d;

        cin >> c >> d;
        Solution obj;
        if (obj.areAnagrams(c, d))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends