class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        int maxlen=0,start=0;
        unordered_map<int,int> hm;
        for(int j=0;j<arr.size();j++){
            hm[arr[j]]++;
            
            while(hm.size()>2){
                hm[arr[start]]=hm[arr[start]]-1;
                if(hm[arr[start]]==0){
                    hm.erase(arr[start]);
                }
                start++;
            }
            maxlen=max(j-start+1, maxlen);
        }
        return maxlen;
    }
};