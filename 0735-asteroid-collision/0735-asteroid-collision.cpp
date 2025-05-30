class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int N=asteroids.size();
        for (int i = 0; i < N; i++) {
            int curr = asteroids[i];
            bool destroyed = false;

            while (!st.empty() && curr < 0 && st.top() > 0) {
                if (st.top() < abs(curr)) {
                    st.pop();  // Top is destroyed, keep checking
                } else if (st.top() == abs(curr)) {
                    st.pop();  // Both destroyed
                    destroyed = true;
                    break;
                } else {
                    // Current is destroyed
                    destroyed = true;
                    break;
                }
            }

            if (!destroyed) {
                st.push(curr);
            }
        }

        // Convert stack to vector
        vector<int> result(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            result[i] = st.top();
            st.pop();
        }

        return result;
    }
};