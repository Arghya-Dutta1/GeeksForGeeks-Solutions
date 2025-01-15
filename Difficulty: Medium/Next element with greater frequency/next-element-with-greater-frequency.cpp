//{ Driver Code Starts
#include <bits/stdc++.h>
#define N 10000
using namespace std;


// } Driver Code Ends
class Solution{
public:
    vector<int> print_next_greater_freq(int arr[],int n)
    {
        // code here
        vector<int> ans;
        unordered_map<int, int> mp;
        for(int i=0;i<n;i++) mp[arr[i]]++;
        
        for(int i=0;i<n;i++){
            int mx=-1;
            for(int j=i+1;j<n;j++)
                if(mp[arr[j]]>mp[arr[i]]){
                    mx=arr[j];
                    break;
                }
            ans.push_back(mx);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int arr[N];
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        for(int i=0; i<n; i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans=ob.print_next_greater_freq(arr,n);
        for(auto x:ans){
            cout<<x<<" ";
        }
        cout << endl;
    
cout << "~" << "\n";
}
	return 1;
}

// } Driver Code Ends