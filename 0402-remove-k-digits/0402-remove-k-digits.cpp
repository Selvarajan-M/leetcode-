class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for (auto x : num) {
            while (!st.empty() && k > 0 && st.top() > x) {
                st.pop();
                k--;
            }
            st.push(x);
        }
        while (k-- && !st.empty()) {
            st.pop();
        }
        string result;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        int i = 0;
        while (i < result.length() && result[i] == '0') {
            i++;
        }
        string trimmed = result.substr(i);
        return trimmed.empty() ? "0" : trimmed;
    
    }
};
