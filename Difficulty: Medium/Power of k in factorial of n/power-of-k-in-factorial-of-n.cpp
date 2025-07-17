class Solution {
  public:
    int maxKPower(int n, int k) {
        // code here
        map<int, int> factors;
        int temp = k;
        for (int i = 2; i * i <= temp; ++i)
            while (temp % i == 0) {
                factors[i]++;
                temp /= i;
            }
        if (temp > 1)
            factors[temp]++;
        int ans = INT_MAX;
        for (auto i: factors) {
            int p=i.first, exp=i.second;
            int count = 0;
            long long power = p;
            while (power <= n) {
                count += n / power;
                power *= p;
            }
            ans = min(ans, count / exp);
        }
        return ans;
    }
};