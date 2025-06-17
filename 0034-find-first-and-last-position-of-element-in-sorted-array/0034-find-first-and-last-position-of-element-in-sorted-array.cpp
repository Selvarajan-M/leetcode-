class Solution {
public:
    int lowerBound(vector<int>& arr, int k) {
        int n = arr.size();
        int low = 0, high = n;
        while (low < high) {
            int mid = low + (high - low) / 2; 
            if (arr[mid] < k)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }
    int upperBound(vector<int>& arr, int target) {
        int n = arr.size();
        int low = 0, high = n;

        while (low < high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] <= target)
                low = mid + 1;
            else
                high = mid;
        }

        return low;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb=lowerBound(nums,target);
        int n=nums.size();
        if(lb==n||nums[lb]!=target) return {-1,-1};
        return {lb,upperBound(nums,target)-1};
    }
};