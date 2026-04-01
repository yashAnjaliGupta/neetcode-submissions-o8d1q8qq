class Solution {
    int movesH[4]={-1,0,1,0};
    int movesV[4]={0,-1,0,1};
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows=heights.size(),columns=heights[0].size();
        vector<vector<bool>> pacVisited(rows,vector<bool>(columns,false));
        vector<vector<bool>> atlVisited(rows,vector<bool>(columns,false));
        cout<<rows<<" "<<columns<<endl;
        for(int i=0;i<rows;i++){
            // cout<<i<<'_'<<0<<endl;
            // cout<<i<<'_'<<columns-1<<endl;
            DFS(heights,pacVisited,i,0);
            DFS(heights,atlVisited,i,columns-1);
        }
        cout<<endl;
        for(int j=0;j<columns;j++){
            // cout<<0<<'_'<<j<<endl;
            // cout<<rows-1<<'_'<<j<<endl;
            DFS(heights,pacVisited,0,j);
            DFS(heights,atlVisited,rows-1,j);
        }
        vector<vector<int>> ans;
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                if(pacVisited[i][j] && atlVisited[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
    void DFS(vector<vector<int>>& heights,vector<vector<bool>>& visited,int idxI,int idxJ){
    
        visited[idxI][idxJ]=true;
        for(int d=0;d<4;d++){
            int i=idxI+movesH[d],j=idxJ+movesV[d];
            if(i>=0 && i<heights.size() && 
            j>=0 && j<heights[0].size() && 
            !visited[i][j]&& heights[i][j]>=heights[idxI][idxJ]){
                DFS(heights,visited,i,j);
            }
        }
    }
};
