class Solution {
  public:
    string removeSpaces(string& s) {
        // code here
        string ans="";
        for(char i:s)
            if(i!=' ')
                ans+=i;
        return ans;
    }
};