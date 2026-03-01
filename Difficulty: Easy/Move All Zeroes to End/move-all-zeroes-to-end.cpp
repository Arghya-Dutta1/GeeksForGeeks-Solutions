// User function template for C++
class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        vector<int> ans(arr.size(), 0);
        int idx=0;
        for(auto i:arr)
            if(i!=0)
                ans[idx++]=i;
        arr=ans;
    }
};
