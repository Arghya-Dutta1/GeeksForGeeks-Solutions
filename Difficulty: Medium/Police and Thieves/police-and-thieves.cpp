class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        // Code here
        int n=arr.size();
        queue<int> tq, pq;
        for (int i = 0; i < n; i++) { 
            if (arr[i] == 'T')
                tq.push(i);
            else
                pq.push(i);
        }
        
		int counter = 0;
        while (!tq.empty() && !pq.empty()) {
            if (abs(tq.front() - pq.front()) <= k) { 
                counter++;
                pq.pop();
                tq.pop();
            }
            else if (tq.front() > pq.front())
                pq.pop();
            else
                tq.pop();
        }
        
        return counter;
    }
};