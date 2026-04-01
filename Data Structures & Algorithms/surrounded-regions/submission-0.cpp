class Solution {
    int moveH[4]={-1,0,1,0};
    int moveV[4]={0,-1,0,1};
public:
    void solve(vector<vector<char>>& board) {
        int rows=board.size(), columns=board[0].size();
        for(int i=0;i<rows;i++){
            DFS(board,i,0);
            DFS(board,i,columns-1);
        }
        for(int j=0;j<columns;j++){
            DFS(board,0,j);
            DFS(board,rows-1,j);
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                if(board[i][j]=='#')board[i][j]='O';
                else if(board[i][j]=='O')board[i][j]='X';
            }
        }
    }
    void DFS(vector<vector<char>>& board,int idxI,int idxJ){
        if(board[idxI][idxJ]!='O'){
            return;
        }
        board[idxI][idxJ]='#';
        for(int d=0;d<4;d++){
            int i=idxI+moveH[d],j=idxJ+moveV[d];
            if(i>=0 && i<board.size() && j>=0 && j<board[0].size() && board[i][j]=='O'){
                DFS(board,i,j);
            }
        }
    }
};
