//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countTriplets(vector<int> &arr, int target) {
        // Code Here
        int ans=0, n=arr.size();
        for(int i=0;i<n;i++){
            int j=i+1, k=n-1;
            while(j<k){
                int sum=arr[i]+arr[j]+arr[k];
                if(sum<target) j++;
                else if(sum>target) k--;
                else{
                    int a=arr[j], b=arr[k], c1=0, c2=0;
                    while(j<=k && arr[j]==a) c1++,j++;
                    while(j<=k && arr[k]==b) c2++,k--;
                    
                    if(a==b) ans+=(c1*(c1-1))/2;
                    else ans+=c1*c2;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

vector<int> lineArray() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> arr;
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }
    return arr;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr = lineArray();
        int target;
        cin >> target;
        cin.ignore();

        Solution ob;
        int res = ob.countTriplets(arr, target);
        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends