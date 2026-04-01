class Solution {
    int moveH[4]={-1,0,1,0};
    int moveV[4]={0,-1,0,1};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int rows=grid.size(),columns=grid[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                if(grid[i][j]==2)
                q.push({i,j});
            }
        }
        int min=0;
        while(!q.empty()){
            int lev=q.size();
            bool rotten=false;
            for(int l=0;l<lev;l++){
                pair<int,int> currPos=q.front();
                int idxI=currPos.first,idxJ=currPos.second;
                q.pop();
                for(int d=0;d<4;d++){
                    int i=idxI+moveH[d],j=idxJ+moveV[d];
                    if(i>=0 && i<rows && j>=0 && j<columns && grid[i][j]==1){
                        q.push({i,j});
                        grid[i][j]=2;
                        rotten=true;
                    }
                }
            }
            if(rotten)min++;
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                if(grid[i][j]==1)
                min=-1;
            }
        }
        return min;
    }
};
