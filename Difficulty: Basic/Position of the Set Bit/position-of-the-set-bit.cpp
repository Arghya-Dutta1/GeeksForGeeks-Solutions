class Solution {
  public:
    int findPosition(int n) {
        // code here
        int i=0, p=0;
        while(p<=n){
            i++;
            p=pow(2,i);
            if(p==n)
                return i+1;
        }
        return -1;
    }
};