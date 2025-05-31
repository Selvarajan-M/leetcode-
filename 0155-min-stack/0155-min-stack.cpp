class MinStack {
    private:
    stack<long long> st;     // Use long long to prevent overflow
    long long mini;

public:
    MinStack() {
        mini = LLONG_MAX;    // Use LLONG_MAX instead of INT_MAX
    }

    void push(int val) {
        long long value = val;  // Convert to long long
        if (st.empty()) {
            mini = value;
            st.push(value);
        } else {
            if (value >= mini) {
                st.push(value);
            } else {
                // Push encoded value
                st.push(2LL * value - mini);
                mini = value;
            }
        }
    }

    void pop() {
        if (st.empty()) return;

        long long top = st.top();
        st.pop();

        if (top < mini) {
            // Recover previous minimum
            mini = 2LL * mini - top;
        }
    }

    int top() {
        if (st.empty()) return -1;

        long long top = st.top();
        if (top >= mini) return (int)top;
        else return (int)mini;
    }

    int getMin() {
        return (int)mini;
    }
};
