class Solution {
  public:
    bool isPalinSent(string &s) {
        // code here
        string s1="";
        for(auto i:s)
            if(isalnum(i))
                s1.push_back(tolower(i));
        s=s1;
        int l=0, r=s.size()-1;
        while(l<=r)
            if(s[l++]!=s[r--])
                return false;
        return true;
    }
};