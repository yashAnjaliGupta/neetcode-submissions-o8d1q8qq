class Solution {
public:
    int lower_bound(vector<vector<int>>& intervals,vector<int>& newInterval,int start,int end){
        if(start>end)return start;
        int mid=(start+end)/2;
        if(intervals[mid][0]>=newInterval[0]){
            return lower_bound(intervals,newInterval,start,mid-1);
        }
        return lower_bound(intervals,newInterval,mid+1,end);
        
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int index=lower_bound(intervals,newInterval,0,intervals.size()-1);
        intervals.insert(intervals.begin() + index, newInterval);
        vector<vector<int>> res;
        for (const auto& interval : intervals) {
            // If res is empty or there is no overlap, add the interval to the
            // result
            if (res.empty() || res.back()[1] < interval[0]) {
                res.push_back(interval);
                // If there is an overlap, merge the intervals by updating the
                // end of the last interval in res
            } else {
                res.back()[1] = max(res.back()[1], interval[1]);
            }
        }

        return res;
    }
};
