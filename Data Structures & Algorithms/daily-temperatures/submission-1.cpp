class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<pair<int, int>> st;
        st.push({0,-1});
        for(int i=temperatures.size()-1;i>=0;i--){
            int t= temperatures[i];
            while(!st.empty() && t>=st.top().first){
                st.pop();
            }
            if(st.empty()){
                res[i]=0;
            }
            else{
                pair<int,int> temp=st.top();
                res[i]= temp.second-i;
            }
            st.push({temperatures[i],i});
        }
        return res;
    }
};
