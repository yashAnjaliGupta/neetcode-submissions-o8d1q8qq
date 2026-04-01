/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
static bool comp(const pair<int,int> &a, const pair<int,int> &b){
    return a.first==b.first?a.second<b.second:a.first<b.first;
}
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<pair<int,int>> time;
        for(int i=0;i<intervals.size();i++){
            time.push_back({intervals[i].start,1});
            time.push_back({intervals[i].end,-1});
        }
        sort(time.begin(),time.end(),comp);
        int res=0,count=0;
        for(int i=0;i<time.size();i++){
            count+=time[i].second;
            res=max(res,count);
        }
        return res;
    }
};
