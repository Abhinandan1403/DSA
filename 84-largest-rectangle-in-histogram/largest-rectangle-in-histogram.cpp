class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
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
};