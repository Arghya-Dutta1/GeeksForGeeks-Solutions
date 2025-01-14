//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    string findLargest(vector<int> &arr) {
        // code here
        vector<string> v;
        for(auto i:arr) v.push_back(to_string(i));
        sort(v.begin(), v.end(), [](string& a, string& b){
            return a+b>b+a;
        });
        
        if(v[0]=="0") return "0";
        
        string ans="";
        for(auto i:v) ans+=i;
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        string ans = ob.findLargest(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends