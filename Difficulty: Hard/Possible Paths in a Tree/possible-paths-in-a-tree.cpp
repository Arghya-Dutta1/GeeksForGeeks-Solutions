//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
	public:
	vector<int> maximumWeight(int n, vector<vector<int>> edges, int q, vector<int> &queries)
	{
	    // code here
	    sort(edges.begin(), edges.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[2] < b[2];
        });

        vector<pair<int, int>> sortedQueries;
        for (int i = 0; i < q; ++i) {
            sortedQueries.push_back({queries[i], i});
        }
        sort(sortedQueries.begin(), sortedQueries.end());

        vector<int> parent(n + 1), size(n + 1, 1);
        iota(parent.begin(), parent.end(), 0); 
        function<int(int)> find = [&](int x) {
            return parent[x] == x ? x : parent[x] = find(parent[x]);
        };

        auto unite = [&](int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX != rootY) {
                if (size[rootX] < size[rootY]) swap(rootX, rootY);
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
            }
        };

        vector<int> result(q, 0);
        long long totalPaths = 0;
        int edgeIndex = 0;

        for (auto &query : sortedQueries) {
            int x = query.first, idx = query.second;

            while (edgeIndex < edges.size() && edges[edgeIndex][2] <= x) {
                int u = edges[edgeIndex][0];
                int v = edges[edgeIndex][1];

                int rootU = find(u);
                int rootV = find(v);

                if (rootU != rootV) {
                    totalPaths -= 1LL * size[rootU] * (size[rootU] - 1) / 2;
                    totalPaths -= 1LL * size[rootV] * (size[rootV] - 1) / 2;
                    unite(u, v);
                    int newRoot = find(u);
                    totalPaths += 1LL * size[newRoot] * (size[newRoot] - 1) / 2;
                }
                ++edgeIndex;
            }

            result[idx] = totalPaths;
        }

        return result;
	}
};



//{ Driver Code Starts.

int main() 
{
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
        cin >> n;
        
        vector<vector<int>> edges(n-1, vector<int> (3, 0));

        for(int i = 0; i < n-1; i++)
        {
        	for(int j = 0; j < 3; j++)
        	{
        		cin >> edges[i][j];
        	}
        }

        int q;
        cin >> q;
        vector<int> queries(q);
        for(int i = 0; i < q; i++)
        	cin >> queries[i];

    	Solution obj;
    	vector<int> ans = obj.maximumWeight(n, edges, q, queries);

    	for(auto i:ans)
    		cout << i << " ";
    	cout << "\n"; 
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends