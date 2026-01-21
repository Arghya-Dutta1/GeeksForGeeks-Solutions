class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        // write code here
        stack<int> st;
        vector<int> ans(arr.size(), 1);
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[i]>=arr[st.top()]) st.pop();
            if(!st.empty())
                ans[i]=i-st.top();
            else
                ans[i]=i+1;
            st.push(i);
        }
        return ans;
    }
};
