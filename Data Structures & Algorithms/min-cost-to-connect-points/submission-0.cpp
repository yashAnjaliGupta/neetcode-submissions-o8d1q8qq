class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<vector<pair<int,int>>> adjL(n);
        for(int i=0;i<n;i++){
            int x1=points[i][0];
            int y1=points[i][1];
            for(int j=i+1;j<n;j++){
                int x2=points[j][0],y2=points[j][1];
                int dist=abs(x1-x2)+abs(y1-y2);
                adjL[i].push_back({j,dist});
                adjL[j].push_back({i,dist});
            }
        }
        int res=0;
        vector<bool> visited(n,false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, 
                                greater<pair<int, int>>> minH;
        minH.push({0,0});
        while(!minH.empty()){
            auto curr=minH.top();
            minH.pop();
            int cost=curr.first;
            int pointN=curr.second;
            if(visited[pointN])continue;
            res+=cost;
            visited[pointN]=true;
            for(int i=0;i<adjL[pointN].size();i++){
                int idx=adjL[pointN][i].first;
                int dist=adjL[pointN][i].second;
                if(!visited[idx]){
                    minH.push({dist,idx});
                }
            }
        }
        return res;
    }
};
