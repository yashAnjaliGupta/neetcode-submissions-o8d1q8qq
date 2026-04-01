class Solution {
    int movesH[4]={-1,0,1,0};
    int movesV[4]={0,-1,0,1};
    int DFS(vector<vector<int>>& grid,vector<vector<bool>> &visited,int idxI,int idxJ,int rows,int columns){
        visited[idxI][idxJ]=true;
        int area=1;
        for(int dir=0;dir<4;dir++){
            int i=idxI+movesV[dir];
            int j= idxJ+movesH[dir];
            if(i>=0 && i<rows && j>=0 && j<columns && !visited[i][j] && grid[i][j]==1){
                area+= DFS(grid,visited,i,j,rows,columns);
            }
        }
        return area;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows=grid.size(),columns=grid[0].size();
        vector<vector<bool>> visited(rows,vector<bool>(columns,false));

        int maxArea=0,area=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                if(grid[i][j] &&!visited[i][j]){
                    area=DFS(grid,visited,i,j,rows,columns);
                    maxArea=max(area,maxArea);
                }
            }
        }
        return maxArea;
    }
};
