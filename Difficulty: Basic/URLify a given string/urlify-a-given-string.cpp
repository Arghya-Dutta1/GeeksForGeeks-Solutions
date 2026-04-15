class Solution {
  public:
    string URLify(string &s) {
        // code here
        string ans="";
        for(auto i:s)
            if(i==' ')
                ans+="%20";
            else
                ans+=i;
        return ans;
    }
};