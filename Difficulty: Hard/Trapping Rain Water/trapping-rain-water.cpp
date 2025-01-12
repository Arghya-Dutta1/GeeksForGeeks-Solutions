//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxWater(vector<int> &height) {
        // code here
        int n=height.size();
        vector<int> left(n);
        vector<int> right(n);

        left[0]=height[0];
        for(int i=1;i<n;i++){
    	    left[i]=max(left[i-1],height[i]);
	    }
	
	    right[n-1]=height[n-1];
	    for(int i=n-2;i>=0;i--){
		    right[i]=max(right[i+1],height[i]);
	    }

        int s=0;
	    for(int i=0;i<n;i++){
		    s+=(min(left[i], right[i])-height[i]);
	    }

        return s;
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends