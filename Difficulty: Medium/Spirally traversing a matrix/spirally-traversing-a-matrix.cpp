//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
        // code here
        vector<int> ans;
        int i=0,j=0,r=matrix.size(),c=matrix[0].size(), rs=r-1, cs=c, count=0, di=0;
        int dr[] = { 0, 1, 0, -1 };
        int dc[] = { 1, 0, -1, 0 };
        while(ans.size()<r*c){
            if(i>=0 && i<r && j>=0 && j<c){
                ans.push_back(matrix[i][j]);
                count++;
            }
            if(count==rs && abs(dr[di])){
                rs--;
                di=(di+1)%4;
                count=0;
            }
            if(count==cs && abs(dc[di])){
                cs--;
                di=(di+1)%4;
                count=0;
            }
            i+=dr[di];
            j+=dc[di];
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++) {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends