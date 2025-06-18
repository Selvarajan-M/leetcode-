class Solution {
public:
    int findMin(vector<int>& nums) {
       int low = 0, high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] > nums[high]) {
                // Minimum is in right half
                low = mid + 1;
            } else if (nums[mid] < nums[high]) {
                // Minimum is in left half or at mid
                high = mid;
            } else {
                // nums[mid] == nums[high], can't determine, reduce search space
                high--;
            }
        }

        return nums[low];
    }
};