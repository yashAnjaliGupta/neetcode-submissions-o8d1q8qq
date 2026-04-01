class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> pairs;
        for(int i=0;i<position.size();i++){
            pairs.push_back({position[i],speed[i]});
        }
        sort(pairs.begin(),pairs.end(),greater<pair<int,int>>());
        stack<double> st;
        for(int i=0;i<pairs.size();i++){
            double endTime=(double)(target-pairs[i].first)/pairs[i].second,newEndTime=endTime;
            if(!st.empty()&&endTime<=st.top())newEndTime=st.top();
            while(!st.empty()&&newEndTime<=st.top()){
                cout<<"pop"<<st.top()<<endl;
                st.pop();
            }
            cout<<newEndTime<<" "<<endTime<<endl;
            st.push(newEndTime);
        }
        return st.size();
    }
};
