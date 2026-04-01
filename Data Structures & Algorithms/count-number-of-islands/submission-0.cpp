class Solution {
    int movesH[4]={-1,0,1,0};
    int movesV[4]={0,1,0,-1};
    void DFS(vector<vector<char>>& grid,vector<vector<bool>>& visited,int idxI,int idxJ,int &rows,int &columns){
        visited[idxI][idxJ]=true;
        for(int i=0;i<4;i++){
            int currI=idxI+movesV[i],currJ=idxJ+movesH[i];
            if(currI>=0 && currI<rows && currJ>=0 && currJ<columns && !visited[currI][currJ] && grid[currI][currJ]=='1'){
                DFS(grid,visited,currI,currJ,rows,columns);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows=grid.size();int columns=grid[0].size();
        vector<vector<bool>> visited(rows,vector<bool>(columns,false));
        int numIsland=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                if(grid[i][j]=='1'&&!visited[i][j]){
                    DFS(grid,visited,i,j,rows,columns);
                    numIsland++;
                }
            }
        }
        return numIsland;
    }
};
