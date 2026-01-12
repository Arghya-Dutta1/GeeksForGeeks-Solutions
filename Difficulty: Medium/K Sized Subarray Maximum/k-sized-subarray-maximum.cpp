
class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& nums, int k) {
        // code here
        int n=nums.size();
        vector<int> ans;
        deque<vector<int>> dq;
        for(int i=0;i<n;i++){
            while(!dq.empty() && dq.back()[0]<=nums[i]){
                dq.pop_back();
            }
            while(!dq.empty() && dq.front()[1]<i-k+1){
                dq.pop_front();
            }
            dq.push_back({nums[i],i});
            if(i>=k-1){
                ans.push_back(dq.front()[0]);
            }
        }
        return ans;
    }
};

