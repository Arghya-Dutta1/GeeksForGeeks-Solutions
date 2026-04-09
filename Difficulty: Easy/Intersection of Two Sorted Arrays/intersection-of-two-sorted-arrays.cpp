class Solution {
  public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        // code here
        int i=0,j=0,n=a.size(),m=b.size();
        vector<int> r;
        while(i<n && j<m){
            if(a[i]<b[j]) i++;
            else if(a[i]>b[j]) j++;
            else{
                if(r.empty()||r.back()!=a[i]) r.push_back(a[i]);
                int x=a[i],y=b[j];
                while(i<n && a[i]==x) i++;
                while(j<m && b[j]==y) j++;
            }
        }
        return r;
    }
};