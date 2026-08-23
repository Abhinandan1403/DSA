class Solution {
public:
    int f(vector<int>& heights) {
        int n = heights.size();
        vector<int> nsr(n, n);
        vector<int> nsl(n, -1);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[i] <= heights[st.top()]) {
                st.pop();
            }
            if (st.empty()) {
                st.push(i);
                continue;
            }
            nsr[i] = st.top();
            st.push(i);
        }
        while (!st.empty()) {
            st.pop();
        }
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[i] <= heights[st.top()]) {
                st.pop();
            }
            if (st.empty()) {
                st.push(i);
                continue;
            }
            nsl[i] = st.top();
            st.push(i);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, abs(nsr[i] - nsl[i] - 1) * heights[i]);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix[0].size();
        int m = matrix.size();
        vector<int> v(n, 0);
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    v[j]++;
                } else {
                    v[j] = 0;
                }
            }
            int val = f(v);
            ans = max(ans, val);
        }
        return ans;
    }
};