class Solution {
  public:
    int cntSubarrays(vector<int> &a, int k) {
        // code here
        unordered_map<int, int> mp;
	    mp[0]=1;
	
	    int csum=0, ans=0;
        for(int i=0;i<a.size();i++){
    	    csum+=a[i];
    	    if(mp.count(csum-k))
    		    ans+=mp[csum-k];
    	    mp[csum]++;    		
	    }
        return ans;
    }
};