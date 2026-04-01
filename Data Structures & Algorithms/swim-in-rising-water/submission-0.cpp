class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        set<pair<int,int>> visit;
        priority_queue<vector<int>, 
                       vector<vector<int>>, greater<>> minHeap;
        vector<vector<int>> directions ={
            {0,1},{0,-1},{1,0},{-1,0}
        };
        minHeap.push({grid[0][0],0,0});
        visit.insert({0,0});
        while(!minHeap.empty()){
            auto curr=minHeap.top();
            minHeap.pop();
            int t=curr[0],r=curr[1],c=curr[2];
            if(r==n-1 && c== n-1){
                return t;
            }
            for(int i=0;i<4;i++){
                int neiR=r+directions[i][0],neiC=c+directions[i][1];
                if(neiR<0|| neiR ==n || neiC<0 || neiC==n || visit.count({neiR,neiC}))continue;
                visit.insert({neiR,neiC});
                minHeap.push({max(t,grid[neiR][neiC]),neiR,neiC});
            }
        }
        return n*n;
    }
};
