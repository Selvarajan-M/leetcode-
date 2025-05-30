class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int largest=nums[i],smallest=nums[i];
            for(int j=i+1;j<n;j++){
                largest=max(largest,nums[j]);
                smallest=min(smallest,nums[j]);
                sum=(largest-smallest)+sum;
            }
        } 
        return sum;
    }
};