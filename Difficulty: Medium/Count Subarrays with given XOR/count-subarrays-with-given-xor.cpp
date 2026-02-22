class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        int xr=0;
        long c=0;
        unordered_map<int, int> mp;
        mp[0]=1;
        for(int i=0;i<arr.size();i++){
            xr^=arr[i];
            int x=xr^k;
            c+=mp[x];
            mp[xr]++;
        }
        return c;
    }
};

static const int __ = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
