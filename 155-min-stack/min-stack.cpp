class MinStack {
private:
    long long mn;
    stack<long long> st;

public:
    MinStack() {}

    void push(int x) {
        if (st.empty()) {
            st.push(0);
            mn = x;
        } else {
            st.push((long long)x - mn);

            if (x < mn)
                mn = x;
        }
    }

    void pop() {
        if (st.empty())
            return;

        long long val = st.top();
        st.pop();

        if (val < 0)
            mn = mn - val; // restore previous minimum
    }

    int top() {
        long long val = st.top();

        if (val > 0)
            return (int)(mn + val);
        else
            return (int)mn;
    }

    int getMin() { return (int)mn; }
};