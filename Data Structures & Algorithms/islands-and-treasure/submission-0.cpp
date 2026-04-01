class Solution {
    int dir[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows=grid.size(),columns=grid[0].size();
        vector<vector<bool>> visited(rows,vector<bool>(columns,false));
        queue<pair<int,int>> BFSq;
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                if(grid[i][j]==0){
                    BFSq.push({i,j});
                }
            }
        }
        while(!BFSq.empty()){
            pair<int,int> currPos=BFSq.front();
            BFSq.pop();
            // cout<<currPos.first<<"-"<<currPos.second<<endl;
            visited[currPos.first][currPos.second]=true;
            for(int d=0;d<4;d++){
                int i=currPos.first+dir[d][0];
                int j=currPos.second+dir[d][1];
                if(i>=0 && i<rows && j>=0 && j<columns &&
                !visited[i][j]&&grid[i][j]==2147483647){
                    grid[i][j]=grid[currPos.first][currPos.second]+1;
                    BFSq.push({i,j});
                }
            }
        }
    }
};
