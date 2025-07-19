class Solution {
  public:
    int fact(int n){
        if(n==0) return 1;
        return n*fact(n-1);
    }
    int vowelCount(string& s) {
        // code here
        unordered_set<char> v={'a', 'e', 'i', 'o', 'u'};
        unordered_map<char, int> mp;
        for(auto i:s) 
            if(v.count(i))
                mp[i]++;
        if(mp.size()==0) return 0;
        int ans=fact(mp.size());
        for(auto i:mp)
            ans*=i.second;
        return ans;
    }
};