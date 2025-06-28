class Solution { 
public:
     int findmax(vector<int> &arr){
    int maxi=INT_MIN;
    for(int num:arr){
        maxi=max(maxi,num);
    }
    return maxi;
    }
    
    int findsum(vector<int>&arr){
        int sum=0;
        for(int num:arr){
            sum+=num;
        }
        return sum;
    }
     int func(vector<int> &arr,int mid){
        int ele=1,subarraySum=0,n=arr.size();
        for(int i=0;i<n;i++){
            if(subarraySum+arr[i]<=mid){
                subarraySum+=arr[i];
            }
            else{
                ele++;
                subarraySum=arr[i];
            }
        }
        return ele;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        if(k > n) return -1;
        int low=findmax(nums),high=findsum(nums);
        while(low<=high){
            int mid=(low+high)/2;
            int noOfSub=func(nums,mid);
            if(noOfSub > k) low=mid+1;
            else high=mid-1;
        }
        return low;
    }
};