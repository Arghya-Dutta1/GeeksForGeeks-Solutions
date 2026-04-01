class Solution {
  public:
    int countStrings(int n) {
        // code here
        if (n == 1)
            return 2;

        int endWith0 = 1, endWith1 = 1;

        for (int i = 2; i <= n; i++) {
            int newEndWith0 = endWith0 + endWith1;
            int newEndWith1 = endWith0;

            endWith0 = newEndWith0;
            endWith1 = newEndWith1;
        }

        return endWith0 + endWith1;
    }
};