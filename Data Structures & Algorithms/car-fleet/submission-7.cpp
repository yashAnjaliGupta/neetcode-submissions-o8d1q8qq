class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> pairs;
        for(int i=0;i<position.size();i++){
            pairs.push_back({position[i],speed[i]});
        }
        sort(pairs.begin(),pairs.end(),greater<pair<int,int>>());
        double prevTime= (double)(target-pairs[0].first)/pairs[0].second;
        int fleets=1;
        for(int i=1;i<pairs.size();i++){
            double currTime=(double)(target-pairs[i].first)/pairs[i].second;
            if(currTime>prevTime){
                fleets++;
                prevTime=currTime;
            }
        }
        return fleets;
    }
};
