class Solution {
  public:
    vector<int> leafNodes(vector<int>& preorder) {
        // code here
        vector<int> leaves;
        if (preorder.empty()) return leaves;
        stack<pair<int, int>> st;
        st.push({0, (int)preorder.size() - 1});

        while (!st.empty()) {
            int start=st.top().first , end=st.top().second;
            st.pop();
            if (start > end) continue;
            if (start == end) {
                leaves.push_back(preorder[start]);
                continue;
            }
            int rootVal = preorder[start], j = start + 1;
            while (j <= end && preorder[j] < rootVal) {
                j++;
            }

            int leftStart = start + 1, leftEnd = j - 1, rightStart = j, rightEnd = end;
            bool isLeaf = (leftStart > leftEnd) && (rightStart > rightEnd);

            if (isLeaf)
                leaves.push_back(rootVal);
            else {
                st.push({rightStart, rightEnd});
                st.push({leftStart, leftEnd});
            }
        }
        return leaves;
    }
};