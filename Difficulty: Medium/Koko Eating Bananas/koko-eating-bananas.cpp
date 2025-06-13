class Solution {
  public:
    bool func(vector<int>& arr, int k, int m){
        int h=0;
        for(auto i:arr) h+=(i+m-1)/m;
        return h<=k;
    }
  
    int kokoEat(vector<int>& arr, int k) {
        // Code here
        int mx=INT_MIN;
        for(auto i:arr) mx=max(mx, i);
        int l=1,h=mx,ans=l;
        while(l<=h){
            int m=l+(h-l)/2;
            if(func(arr, k, m)){
                ans=m;
                h=m-1;
            }
            else
                l=m+1;
        }
        return ans;
    }
};