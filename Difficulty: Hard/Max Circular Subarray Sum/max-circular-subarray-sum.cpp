class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {

        // your code here
        int tsum=0, cmxsum=0, cmnsum=0, mxsum=INT_MIN, mnsum=INT_MAX;
        for(auto i:arr){
            tsum+=i;
            cmxsum=max(cmxsum+i, i);
            cmnsum=min(cmnsum+i, i);
            mxsum=max(mxsum, cmxsum);
            mnsum=min(mnsum, cmnsum);
        }
        return mxsum<0?mxsum:max(mxsum, tsum-mnsum);
    }
};
