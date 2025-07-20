class Solution {
public:
    int countValid(int n, vector<int>& arr) {
        vector<bool> badDigit(10, false);
        for (int d : arr) badDigit[d] = true;

        vector<int> allowed;
        for (int i = 0; i <= 9; i++)
            if (!badDigit[i]) allowed.push_back(i);

        int total = 9 * pow(10, n - 1);
        int invalid = countWithoutBadDigits(n, allowed);
        return total - invalid;
    }

    int countWithoutBadDigits(int n, vector<int>& allowed) {
        int m = allowed.size();
        if (m == 0) return 0;

        int count = 0;
        for (int d : allowed)
            if (d != 0)
                count += helper(n - 1, allowed);
        return count;
    }

    int helper(int pos, vector<int>& allowed) {
        return pow(allowed.size(), pos);
    }
};
