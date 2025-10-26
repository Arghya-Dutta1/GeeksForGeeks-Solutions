class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    int minCost(vector<int>& arr) {
        // Your code here
        priority_queue<int> pq;
        for(auto i:arr) pq.push(-1*i);
        int sum=0;
        while(pq.size()>1){
            int f=-1*pq.top();
            pq.pop();
            int s=-1*pq.top();
            pq.pop();
            sum+=f+s;
            pq.push(-1*(f+s));
        }
        return sum;
    }
};

