
class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Your code here
        vector<vector<int>> ans;
        priority_queue<pair<int, vector<int>>> pq;
        for(const auto& i:points){
            pq.push({i[0]*i[0]+i[1]*i[1],i});
            if(pq.size()>k)
                pq.pop();
        }
        while(!pq.empty())
            ans.push_back(pq.top().second), pq.pop();
        return ans;
    }
};

