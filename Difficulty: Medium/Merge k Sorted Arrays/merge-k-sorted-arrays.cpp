// User function Template for C++

class Solution {
  public:
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>>& arr, int K) {
        // code here
        typedef tuple<int, int, int> T;
        priority_queue<T, vector<T>, greater<T>> pq;
        for (int i = 0; i < K; i++)
            pq.push(make_tuple(arr[i][0], i, 0));
        vector<int> res;
        while (!pq.empty()) {
            T t = pq.top(); pq.pop();
            int val = get<0>(t), row = get<1>(t), col = get<2>(t);
            res.push_back(val);
            if (col + 1 < arr[row].size())
                pq.push(make_tuple(arr[row][col + 1], row, col + 1));
        }
        return res;
    }
};