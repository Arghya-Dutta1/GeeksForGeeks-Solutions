//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int TotalPairs(vector<int>nums, int k){
	    // Code here
	    unordered_set<int> s;
        set<pair<int, int>> p;

        for(int i:nums){
            if(s.find(i+k)!=s.end()) p.insert({i, i+k});
            if(s.find(i-k)!=s.end()) p.insert({i-k, i});
            s.insert(i);
        }

        return p.size();
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
		cin >> n >> k;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.TotalPairs(nums, k);
		cout << ans <<"\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends