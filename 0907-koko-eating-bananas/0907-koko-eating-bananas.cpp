class Solution {
public:
    long long findTotalHrs(vector<int>& piles, int mid){
        long long totalhrs=0;
        int n=piles.size();
        for(int i=0;i<n;i++){
            totalhrs+=ceil((double)piles[i]/(double)mid);
        }
        return totalhrs;
    }
    int findMax(vector<int>& piles){
        int maxi=INT_MIN;
        int n=piles.size();
        for(int i=0;i<n;i++){
            maxi=max(maxi,piles[i]);
        }
        return maxi;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long low=1, high=findMax(piles);
        int ans=INT_MAX;
        int n=piles.size();
        while(low<=high){
            long long mid=low+(high-low)/2;
            long long totalhrs=findTotalHrs(piles,mid);
            if(totalhrs <= h){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;

    }
};