//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the minimum element in sorted and rotated array.
    int minNumber(int nums[], int low, int high)
    {
        // Your code here
        int l=0, r=high;
        //nums.size()-1;
        while(l<r){
            int m=(l+r)/2;
            if(nums[m]>nums[r])
                l=m+1;
            else if(nums[m]<nums[r])
                r=m;
            else
                r--;
        }
        return nums[l];
        
    }
};

//{ Driver Code Starts.


int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];	
		Solution obj;
		cout << obj.minNumber(a,0,n-1) << endl;
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends