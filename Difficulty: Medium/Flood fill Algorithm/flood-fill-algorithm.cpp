//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void dfs(vector<vector<int>>& img, int r, int c, int o, int n){
        if(r<0 || c<0 || r>=img.size() || c>=img[0].size()) return;   
        if(img[r][c]!=o) return;
        img[r][c]=n;
        dfs(img, r+1, c, o, n);
        dfs(img, r, c+1, o, n);
        dfs(img, r-1, c, o, n);
        dfs(img, r, c-1, o, n);
    }
  
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        // Code here
        int old=image[sr][sc];
        if(old!=newColor)
            dfs(image, sr, sc, old, newColor);
        return image;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans) {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends