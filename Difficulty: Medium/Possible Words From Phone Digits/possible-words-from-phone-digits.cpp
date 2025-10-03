class Solution {
  public:
    vector<string> ans;
    void combo(vector<int>& d, int ind, string& c, vector<string>& n){
        if(ind>=d.size()){
            ans.push_back(c);
            return;
        }

        int digit=d[ind];
        
         if(n[digit].empty()){
            combo(d, ind+1, c, n);
            return;
        }

        string val=n[digit];
        for(int i=0;i<val.size();i++){
            c.push_back(val[i]);
            combo(d, ind+1, c, n);
            c.pop_back();
        }
    }
    vector<string> possibleWords(vector<int> &digits) {
        // code here
        if(digits.size()==0)
            return {};
        vector<string> num={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string c="";
        combo(digits, 0, c, num);
        return ans;
    }
};