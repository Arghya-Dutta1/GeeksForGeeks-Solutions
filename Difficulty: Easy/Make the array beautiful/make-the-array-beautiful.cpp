class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        // code here
        vector<int> ans;
        stack<int> st;
        for(auto i:arr){
            if(st.empty())
                st.push(i);
            else{
                int e=st.top();
                if((e>=0 && i>=0) || (e<0 && i<0))
                    st.push(i);
                else
                    st.pop();
            }
        }
        while(!st.empty()){
            ans.insert(ans.begin(), st.top());
            st.pop();
        }
        return ans;
    }
};