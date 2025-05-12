class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        int maxi = nums[0];
        int n = nums.size();

        for (int i = 1; i < n; i++) {
            sum = max(nums[i], sum + nums[i]);
            maxi = max(maxi, sum);
        }
        return maxi;
    }
};
