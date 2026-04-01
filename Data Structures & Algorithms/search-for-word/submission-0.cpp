class Solution {
private:
    bool dfs(vector<vector<char>>& board, string word,int sIdx,int iIdx,int jIdx){
        if(sIdx==word.length())return true;
        if(iIdx<0 || iIdx>=board.size()|| jIdx<0 || jIdx>=board[0].size() 
        || board[iIdx][jIdx]!=word[sIdx]||board[iIdx][jIdx]=='#')return false;
        
        board[iIdx][jIdx]='#';
        bool res =  dfs(board,word,sIdx+1,iIdx-1,jIdx)||
                    dfs(board,word,sIdx+1,iIdx,jIdx-1)||
                    dfs(board,word,sIdx+1,iIdx+1,jIdx)||
                    dfs(board,word,sIdx+1,iIdx,jIdx+1);
        board[iIdx][jIdx]=word[sIdx];
        return res;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(dfs(board,word,0,i,j))return true;
            }
        }
        return false;
    }
};
