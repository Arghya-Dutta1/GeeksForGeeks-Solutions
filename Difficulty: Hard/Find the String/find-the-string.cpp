//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string findString(int n, int k) {
        string result;
        string start(n - 1, '0');
        unordered_set<string> visited;
        
        dfs(start, k, visited, result);
        
        result += start;
        return result;
    }

private:
    void dfs(const string& node, int k, unordered_set<string>& visited, string& result) {
        for (int i = 0; i < k; i++) {
            string edge = node + char('0' + i);
            if (visited.find(edge) == visited.end()) {
                visited.insert(edge);
                dfs(edge.substr(1), k, visited, result);
                result += char('0' + i);
            }
        }
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        cin>>N>>K;
        Solution ob;
        string ans = ob.findString(N, K);
        int ok=1;
        for(auto i:ans){
            if(i<'0'||i>K-1+'0')
                ok=0;
        }
        if(!ok){
            cout<<-1<<endl;
            continue;
        }
        unordered_set<string> st;
        for(int i=0;i+N-1<ans.size();i++){
            st.insert(ans.substr(i,N));
        }
        int tot=1;
        for(int i=1;i<=N;i++)
            tot*=K;
        if(st.size()==tot)
        {
            cout<<ans.size()<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    
cout << "~" << "\n";
}
    return 0;
} 
// } Driver Code Ends