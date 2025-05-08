class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<long long, int> preSumMap;
        long long sum = 0;
        int count = 0;
        
        // Initialize map with prefix sum 0 having frequency 1
        preSumMap[0] = 1;
        
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            
            // If (sum - k) exists, add its frequency to count
            if (preSumMap.find(sum - k) != preSumMap.end()) {
                count += preSumMap[sum - k];
            }
            
            // Update the frequency of the current prefix sum
            preSumMap[sum]++;
        }
        
        return count;
    }
};