class Solution {
public:
    int firstUniqChar(string s) {
        int n=s.length();
        if(n==0)
        return -1;
        vector<int>count(256,0);
        for(int i=0;i<n;i++){
            count[s[i]]++;
        }
        for(int i=0;i<n;i++){
            if(count[s[i]]==1)
            return i;
        }
        return  -1;
    }
};