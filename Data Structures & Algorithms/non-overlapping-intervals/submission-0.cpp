class Solution {
static bool comp(const vector<int> &a,const vector<int> &b){
    return a[0]<b[0];
} 
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int prevEnd=intervals[0][1];
        int ans=0;
        for(int i=1;i<intervals.size();i++){
            if(prevEnd>intervals[i][0]){
                prevEnd=min(intervals[i][1],prevEnd);
                ans++;
            }else{
                prevEnd=intervals[i][1];
            }
        }
        return ans;
    }
};
