class Solution {
  public:
    int binarysearch(vector<int> &arr, int k) {
        // code here
        int l=0,r=arr.size()-1, ans=-1;
        while(l<=r){
            int md=l+(r-l)/2;
            if(arr[md]==k){
               ans=md;
               r=md-1;
            }
            else if(arr[md]>k) r=md-1;
            else l=md+1;
        }
        return ans;
    }
};