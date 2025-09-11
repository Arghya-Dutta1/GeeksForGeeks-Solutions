class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // code here
        int n=arr.size();
        if(n<=1) return 0;
        if(arr[0]==0) return -1;
        
        int mx=arr[0], s=arr[0], j=1;
        for(int i=1;i<n;i++){
            if(i==n-1) return j;
            mx=max(mx, i+arr[i]);
            s--;
            if(s==0){
                j++;
                if(i>=mx) return -1;
                s=mx-i;
            }
        }
        return -1;
    }
};
