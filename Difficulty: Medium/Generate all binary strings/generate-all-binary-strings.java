class Solution {
    public ArrayList<String> binstr(int n) {
        // code here
        ArrayList<String> ans=new ArrayList<String>();
        helper(ans, "", n);
        return ans;
    }
    void helper(ArrayList<String> ans, String cur, int n){
        if(cur.length()==n){
            ans.add(cur);
            return;
        }
        helper(ans, cur+'0', n);
        helper(ans, cur+'1', n);
    }
}
