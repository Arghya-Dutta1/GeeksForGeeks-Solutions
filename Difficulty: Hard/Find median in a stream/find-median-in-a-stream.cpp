//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        // code here
        vector<double> ans;
        priority_queue<int> mx;
        priority_queue<int, vector<int>, greater<int>> mn;
        for(auto& i:arr){
            mx.push(i);
            mn.push(mx.top());
            mx.pop();

            if(mn.size()>mx.size()){
                mx.push(mn.top());
                mn.pop();
            }
            
            if(mx.size()>mn.size())
                ans.push_back(mx.top()*1.0);
            else
                ans.push_back((mx.top()+mn.top())/2.0);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<double> ans = ob.getMedian(nums);
        cout << fixed << setprecision(1);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends