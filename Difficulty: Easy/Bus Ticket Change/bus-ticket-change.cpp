class Solution {
  public:
    bool canServe(vector<int> &arr) {
        // code here
        int cnt5 = 0, cnt10 = 0;
        for (int note : arr) {
            if (note == 5) {
                cnt5++;
            } 
            else if (note == 10) {
                if (cnt5 == 0) return false;
                cnt5--;
                cnt10++;
            } 
            else {
                if (cnt10 > 0 && cnt5 > 0) {
                    cnt10--;
                    cnt5--;
                } 
                else if (cnt5 >= 3) {
                    cnt5 -= 3;
                } 
                else {
                    return false;
                }
            }
        }
        return true;
    }
};