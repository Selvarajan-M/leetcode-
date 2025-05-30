class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        return sumMax(nums)-sumMin(nums);
    }
private:
   long long sumMin(const vector<int>& nums){
    int n=nums.size();
    stack<int>st;
    long long res=0;
    for(int i=0;i<=n;i++){
        while(!st.empty()&&(i==n||nums[st.top()]>=(i<n?nums[i]:INT_MIN))){
            int mid=st.top();st.pop();
            int left=st.empty()?-1:st.top();
            int right=i;
            long long count = (mid - left) * (right - mid);
            res+=count*nums[mid]; 
        }
        st.push(i);
    }
    return res;
   }

   long long sumMax(const vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        long long res = 0;

        for (int i = 0; i <= n; ++i) {
            while (!st.empty() && (i == n || nums[st.top()] <= (i < n ? nums[i] : INT_MAX))) {
                int mid = st.top(); st.pop();
                int left = st.empty() ? -1 : st.top();
                int right = i;
                long long count = (mid - left) * (right - mid);
                res += count * nums[mid];
            }
            st.push(i);
        }
        return res;
    }
};