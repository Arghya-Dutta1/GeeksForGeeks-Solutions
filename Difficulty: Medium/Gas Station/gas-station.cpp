

/*You are required to complete this method*/
class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        // Your code here
        int total=0, req=0;
        for(int i=0;i<cost.size();i++){
            req+=cost[i];
            total+=gas[i];
        }
        if(total < req)
            return -1;
        int ans=0, currgas=0;
        for(int i=0;i<gas.size();i++){
            currgas+=gas[i]-cost[i];
            if(currgas<0) {
                ans=i+1;
                currgas=0;
            }
        }
        return ans;
    }
};


