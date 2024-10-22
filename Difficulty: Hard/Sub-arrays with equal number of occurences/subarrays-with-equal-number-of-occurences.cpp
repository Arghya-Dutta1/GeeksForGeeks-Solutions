//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int sameOccurrence(vector<int>& A, int B, int C) {
    int n=A.size(),ans=0,cnt=0;
    unordered_map<int,int>r;
    for(int i=0;i<n;i++){
        if(A[i]==B)
            cnt++;

        if(A[i]==C)
            cnt--;
        
        if(cnt==0)
            ans++;
        
        ans+=r[cnt];
       
        r[cnt]++;
    }
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
        string ks;
        getline(cin, ks);
        int x = stoi(ks);
        string ks1;
        getline(cin, ks1);
        int y = stoi(ks1);
        Solution ob;
        int ans = ob.sameOccurrence(arr, x, y);
        cout << ans << "\n";
        // cout<<"~"<<endl;
    }
    return 0;
}
// } Driver Code Ends