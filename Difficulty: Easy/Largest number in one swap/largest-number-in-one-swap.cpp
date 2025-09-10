class Solution {
  public:
    string largestSwap(string &s) {
        // code here
        vector<int> li(10, -1);
        for(int i=0;i<s.size();i++)
            li[s[i]-'0']=i;

        for(int i=0;i<s.size();i++)
            for(int d=9;d>s[i]-'0';d--)
                if(li[d]>i){
                    swap(s[i], s[li[d]]);
                    return s;
                }
        return s;
    }
};