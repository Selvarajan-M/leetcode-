class Solution {
public:
    static bool comp(const vector<int>& val1, const vector<int>& val2){
        return val1[1] < val2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int cnt=1,lastEndTime=intervals[0][1],n=intervals.size();
        for(int i=1;i<n;i++){
            if(intervals[i][0] >= lastEndTime){
                cnt=cnt+1;
                lastEndTime=intervals[i][1];
            }
        }
        return n-cnt;
    }
};