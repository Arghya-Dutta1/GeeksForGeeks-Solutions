class Solution {
    public ArrayList<String> generateBinary(int n) {
        // code here
        ArrayList<String> ans = new ArrayList<>();
        for(int i=1;i<=n;i++){
            String s=Integer.toBinaryString(i);
            ans.add(s);
        }
        return ans;
    }
}
