class Solution {
public:
    int largestHistogram(vector<int> &arr) {
        // Your code here
        stack<int>st;
        int n=arr.size();
        int maxarea=0;
        for(int i=0;i<n;i++){
            while(!st.empty()&&arr[st.top()]>arr[i]){
                int currel=st.top();
                st.pop();
                int nse=i;
                int pse=st.empty()?-1:st.top();
                maxarea=max(maxarea,arr[currel]*(nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty())
        {
            int nse=n;
            int currel=st.top();
            st.pop();
            int pse=st.empty()?-1:st.top();
            maxarea=max(maxarea,arr[currel]*(nse-pse-1));
        }
        return maxarea;
    }
     int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int n = matrix.size(), m = matrix[0].size(), maxarea = 0;
        vector<int> heights(m, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') {
                    heights[j] += 1;
                } else {
                    heights[j] = 0;
                }
            }
            maxarea = max(maxarea, largestHistogram(heights));
        }

        return maxarea;
    }
};