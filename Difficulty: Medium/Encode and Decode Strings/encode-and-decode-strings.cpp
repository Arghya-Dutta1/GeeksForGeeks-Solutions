//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string encode(vector<string>& s) {
        // code here
        string encoded = "";
        for (const string& str : s) 
            encoded += to_string(str.size()) + "#" + str;
        return encoded;
    }

    vector<string> decode(string& s) {
        // code here
        vector<string> decoded;
        int i = 0;
        while (i < s.size()) {
            int j = i;
            while (s[j] != '#') ++j;
            int len = stoi(s.substr(i, j - i));
            decoded.push_back(s.substr(j + 1, len));
            i = j + 1 + len;
        }
        return decoded;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore(); // To ignore the newline after the number of test cases

    while (tc--) {
        string input;
        getline(cin, input);

        stringstream ss(input);
        string word;
        vector<string> s;

        while (ss >> word) {
            s.push_back(word);
        }

        Solution obj;
        string encodedString = obj.encode(s);
        vector<string> decodedStrings = obj.decode(encodedString);

        for (string x : decodedStrings) {
            cout << x << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends