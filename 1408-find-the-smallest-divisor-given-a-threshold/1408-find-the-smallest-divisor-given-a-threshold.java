class Solution {
    public int  sumofD(int[] nums,int d,int n){
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=(int) Math.ceil((double) nums[i]/d); //sum += (arr[i] + d - 1) / d;

        }
        return sum;
    }
    public int findmax(int[] nums,int n){
        int maxi=Integer.MIN_VALUE;
        for(int i=0;i<n;i++){
            maxi=Math.max(maxi,nums[i]);
        }
        return maxi;
    }
    public int smallestDivisor(int[] nums, int threshold) {
        int n =nums.length,low=1,high=findmax(nums,n);
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(sumofD(nums,mid,n) <= threshold){
                ans=mid;
                high=mid-1;
            }
            else
            low=mid+1;
            
        }
        return ans;
    }
}