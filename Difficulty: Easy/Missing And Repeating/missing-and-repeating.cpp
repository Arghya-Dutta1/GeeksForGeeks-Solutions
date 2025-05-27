class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        unordered_set<int> st;
        int a=-1, b=-1;
        for(auto i:arr){
            if(st.count(i)) a=i;
            else st.insert(i);
        }
        for(int i=1;i<=arr.size();i++)
            if(!st.count(i)){
                b=i;
                break;
            }
        return {a,b};
    }
};