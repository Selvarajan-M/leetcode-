class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        int total=n*(n+1)/2;
        for(int num: nums){
            total-=num;
        }
        return total;
    }
};