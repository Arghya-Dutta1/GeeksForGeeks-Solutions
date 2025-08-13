class Solution {
  public:
    int minSoldiers(vector<int>& arr, int k) {
        // code here
        int n = arr.size(), target = (n + 1) / 2, count = 0;
        vector<int> req;
        for (int num : arr) {
            if (num % k == 0)
                count++;
            else
                req.push_back(k - (num % k));
        }
        
        if (count >= target)
            return 0;
        sort(req.begin(), req.end());
        int res = 0, need = target - count;
        for (int i = 0; i < need; i++)
            res += req[i];
        return res;
    }
};