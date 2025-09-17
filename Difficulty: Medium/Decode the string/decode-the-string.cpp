

class Solution {
  public:
    string get(string s, int n){
        string ans="";
        while(n--) ans+=s;
        return ans;
    }
    
    string decodedString(string &s) {
        // code here
        stack<pair<string, int>> st;
        string cur="";
        int f=0;
        for(auto i:s){
            if(isdigit(i))
                f=f*10+(i-'0');
            else{
                if(i=='['){
                    st.push({cur, f});
                    cur="";
                    f=0;
                }
                else if(i==']'){
                    string str=st.top().first;
                    int n=st.top().second;
                    st.pop();
                    cur=str+get(cur, n);
                }
                else cur+=i;
            }
        }
        return cur;
    }
};

