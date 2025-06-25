class Solution {
  public:
    bool sameFreq(string& s) {
        // code here
        unordered_map<char, int> mp;
        unordered_map<int, int> f;
        for(auto i:s) mp[i]++;
        for(auto it:mp) f[it.second]++;
        if(f.size()==1) return true;
        else if(f.size()!=2) return false;
        else{
            auto it = f.begin();
            int F1=it->first ,c1=it->second;
            it++;
            int F2=it->first ,c2=it->second;
            if((F1==1 && c1==1) || (F2==1 && c2==1)) return true;
            if((abs(F1-F2)==1) && ((F1>F2 && c1==1) || (F2>F1 && c2==1))) return true;
            return false;
        }
    }
};