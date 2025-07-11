class Solution {
  public:
    int countConsec(int n) {
        // code here
        if (n == 2) return 1;
        int firstNum  = 0, secondNum = 1, thirdNum, result = 1; 
        for (int i = 3; i <= n; ++i) {
            thirdNum  = firstNum + secondNum;     
            result    = result * 2 + thirdNum;    
            firstNum  = secondNum;               
            secondNum = thirdNum;
        }
        return result;
    }
};