class Solution {
  public:
    bool isBinaryPalindrome(int n) {
        // code here
        string s = "";
        
        while (n > 0) {
            s += (n % 2) + '0';
            n /= 2;
        }
        
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        
        return true;
    }
};