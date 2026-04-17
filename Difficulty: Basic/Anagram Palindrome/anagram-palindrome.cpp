class Solution {
  public:
    bool canFormPalindrome(string &s) {
        // code here
        int mask = 0;
        for(char c : s) {
            int bit = c - 'a';
            mask ^= (1 << bit);  
        }
        return (mask & (mask - 1)) == 0;
    }
};