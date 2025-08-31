class Solution {

  public:
    int maxWater(vector<int> &height) {
        // code here
        int l=0,r=height.size()-1;
        int ans=0;
        while(l<r){
            int area=min(height[l], height[r])*(r-l);
            ans=max(ans, area);
            if(height[l]<height[r])
                l++;
            else
                r--;
        }
        return ans;
    }
};
