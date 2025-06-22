class Solution {
public:
    bool possible(vector<int>&bloomDay,int day,int m,int k){
        int cnt=0,nOfb=0,n=bloomDay.size();
        for(int i=0;i<n;i++){
            if(bloomDay[i]<=day)
            cnt++;
            else
            {
                nOfb+=(cnt/k);
                cnt=0;
            }
            
        }
        nOfb+=(cnt/k);
        if(nOfb>=m) return true;
            else return false; 
    }

    int findMin(vector<int>&arr,int n){
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            mini=min(mini,arr[i]);
        }
        return mini;
    }
    int findMax(vector<int>&arr, int n){
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(maxi,arr[i]);
        }
        return maxi;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if(n < (long  long) m*k) return -1;
        int ans=-1;
        int low=findMin(bloomDay,n),high=findMax(bloomDay,n);
        while(low<=high){
            int mid=(low+high)/2;
            if(possible(bloomDay,mid,m,k)==true)
            {
                ans=mid;
                high=mid-1;
            }
            else
            low=mid+1;
        }
        return ans;
    }
};