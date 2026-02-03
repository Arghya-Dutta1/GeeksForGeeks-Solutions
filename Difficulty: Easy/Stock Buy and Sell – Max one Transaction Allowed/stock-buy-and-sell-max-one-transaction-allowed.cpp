class Solution {
  public:
    int maxProfit(vector<int> &p) {
        // code here
        int n=p.size(), ans=0;
        vector<int> pm(n, 0);
        pm[n-1]=p[n-1];
        for(int i=n-2;i>=0;i--) 
            pm[i]=max(p[i], pm[i+1]);
        for(int i=0;i<n;i++)
            ans=max(ans, pm[i]-p[i]);
        return ans;
    }
};

