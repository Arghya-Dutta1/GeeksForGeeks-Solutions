class Solution {
  public:
    set<vector<int>> ans;

    void per(vector<int>& nums, vector<int>& a, vector<bool>& b){
        if(a.size()==nums.size()){
            ans.insert(a);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!b[i]){
                a.push_back(nums[i]);
                b[i]=true;
                per(nums, a, b);
                a.pop_back();
                b[i]=false;
            }
        }
    }
    vector<vector<int>> uniquePerms(vector<int>& nums) {
        // code here
        vector<int> a;
        vector<bool> b(nums.size(), false);
        per(nums, a, b);
        return {ans.begin(), ans.end()};
    }
};