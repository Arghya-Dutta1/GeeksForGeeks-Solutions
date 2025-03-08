//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string longestPalindrome(string &s) {
        // code here
        int n=s.length();
        int x=-1,y=-1;
        int len=0;
        for(int i=0;i<n;i++){
            int j=i-1;
            int k=i+1;
            while(j>=0 and k<n and s[j]==s[k]){
                j--;
                k++;
            }
            int l=k-j-1;
            if(l>len){
                len=l;
                x=j+1;
                y=k-1;
            }
        }
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                int j=i-1;
                int k=i+2;
                  while(j>=0 and k<n and s[j]==s[k]){
                j--;
                k++;
            }
            int l=k-j-1;
            if(l>len){
                len=l;
                x=j+1;
                y=k-1;
            }
            }
        }

        string t="";
        for(int i=x;i<=y;i++)t+=s[i];

        return t;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.longestPalindrome(S) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends