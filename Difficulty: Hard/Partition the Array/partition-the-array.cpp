//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
public:
    long long minDifference(int N, vector<int> &A) {
        vector<long long> prefixSum(N + 1, 0);

        // Compute prefix sum
        for (int i = 1; i <= N; ++i) {
            prefixSum[i] = prefixSum[i - 1] + A[i - 1];
        }

        long long result = LLONG_MAX;

        // Iterate through possible midpoints for Q and R
        for (int mid1 = 2; mid1 < N - 1; ++mid1) {
            // Find the optimal partition for P and Q
            long long minDiff1 = LLONG_MAX;
            int low1 = 1, high1 = mid1 - 1;
            int opt1 = low1;

            while (low1 <= high1) {
                int mid = (low1 + high1) / 2;
                long long leftSum = prefixSum[mid];
                long long rightSum = prefixSum[mid1] - prefixSum[mid];
                long long diff = abs(leftSum - rightSum);

                if (diff < minDiff1) {
                    minDiff1 = diff;
                    opt1 = mid;
                }

                if (leftSum < rightSum) {
                    low1 = mid + 1;
                } else {
                    high1 = mid - 1;
                }
            }

            // Find the optimal partition for R and S
            long long minDiff2 = LLONG_MAX;
            int low2 = mid1 + 1, high2 = N - 1;
            int opt2 = low2;

            while (low2 <= high2) {
                int mid = (low2 + high2) / 2;
                long long leftSum = prefixSum[mid] - prefixSum[mid1];
                long long rightSum = prefixSum[N] - prefixSum[mid];
                long long diff = abs(leftSum - rightSum);

                if (diff < minDiff2) {
                    minDiff2 = diff;
                    opt2 = mid;
                }

                if (leftSum < rightSum) {
                    low2 = mid + 1;
                } else {
                    high2 = mid - 1;
                }
            }

            // Calculate sums for the four partitions
            long long W = prefixSum[opt1];
            long long X = prefixSum[mid1] - prefixSum[opt1];
            long long Y = prefixSum[opt2] - prefixSum[mid1];
            long long Z = prefixSum[N] - prefixSum[opt2];

            // Update result with the minimum difference
            result = min(result, max({W, X, Y, Z}) - min({W, X, Y, Z}));
        }

        return result;
    }
};



//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution ob;
        long long ans = ob.minDifference(N, A);
        cout<<ans<<endl;
    
cout << "~" << "\n";
}
    return 0;
} 
// } Driver Code Ends