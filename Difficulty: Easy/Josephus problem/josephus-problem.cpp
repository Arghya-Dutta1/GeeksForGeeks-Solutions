class Solution {
  public:
    int josephus(int n, int k) {
        // code here
        vector<int> a(n);
        for(int i=1;i<=n;i++) a[i-1]=i;
        int ind=0;
        k--;
        while(a.size()>1){
            int s=a.size();
            ind= (ind+k)%s;
            a.erase(a.begin()+ind);
        }
        return a[0];
    }
};