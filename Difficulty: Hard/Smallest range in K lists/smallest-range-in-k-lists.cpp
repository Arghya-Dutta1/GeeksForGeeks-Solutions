//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> findSmallestRange(vector<vector<int>>& nums) {
        // code here
        vector<pair<int, int>> a;
        for(int i=0;i<nums.size();i++)
            for(auto j:nums[i])
                a.push_back({j, i});
        sort(a.begin(), a.end());
        int mini=1e9, d=nums.size(), t=0, j=0;
        vector<int> ans, mp(d, 0);
        for(int i=0;i<a.size();i++){
            mp[a[i].second]++;
            if(mp[a[i].second]==1) t++;
            if(t==d){
                if(a[i].first-a[j].first+1<mini){
                    mini=a[i].first-a[j].first+1;
                    ans={a[j].first, a[i].first};
                }

                while(t==d){
                    if(mp[a[j].second]>1){
                        mp[a[j].second]--;
                        j++;
                    }
                    else break;
                }

                if(a[i].first-a[j].first+1<mini){
                    mini=a[i].first-a[j].first+1;
                    ans={a[j].first, a[i].first};
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> arr(k, vector<int>(n));

        for (int i = 0; i < k; i++)
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];

        Solution obj;
        vector<int> range = obj.findSmallestRange(arr);
        cout << range[0] << " " << range[1] << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends