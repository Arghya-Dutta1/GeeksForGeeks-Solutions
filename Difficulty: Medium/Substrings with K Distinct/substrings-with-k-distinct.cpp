class Solution {
  public:
    int atMostK(string& s, int k) {
        if (k == 0) return 0;
        vector<int> count(26, 0);
        int left = 0, res = 0, distinct = 0;

        for (int right = 0; right < s.size(); ++right) {
            if (count[s[right] - 'a'] == 0)
                distinct++;
            count[s[right] - 'a']++;

            while (distinct > k) {
                count[s[left] - 'a']--;
                if (count[s[left] - 'a'] == 0)
                    distinct--;
                left++;
            }

            res += (right - left + 1);
        }

        return res;
    }
    int countSubstr(string& s, int k) {
        // code here.
        return atMostK(s, k) - atMostK(s, k - 1);
    }
};