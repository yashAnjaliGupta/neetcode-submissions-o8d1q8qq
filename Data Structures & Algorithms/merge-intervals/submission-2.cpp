class Solution {
 static bool comp(const vector<int>& a,const vector<int>& b){
    return a[0]<b[0];
 }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(),intervals.end(),comp);
        res.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            int lastEndTime=res.back()[1];
            if(intervals[i][0]<=lastEndTime){
                res.back()[1]=max(intervals[i][1],lastEndTime);
            }else{
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};
