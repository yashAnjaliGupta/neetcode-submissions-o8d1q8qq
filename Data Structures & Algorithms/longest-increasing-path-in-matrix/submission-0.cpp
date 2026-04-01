class Solution {
private:
vector<vector<int>> directions = {{-1, 0}, {1, 0}, 
                                      {0, -1}, {0, 1}};
    int dfs(vector<vector<int>>& matrix,int r,int c,int preVal,
    vector<vector<int>>& dp){
        int rows=matrix.size(),cols=matrix[0].size();
        if(r<0||r>=rows||c<0||c>=cols||matrix[r][c]<=preVal)return 0;
        if(dp[r][c]!=-1)return dp[r][c];
        int res=1;
        for(vector<int> d:directions){
            res=max(res,1+dfs(matrix,r+d[0],c+d[1],matrix[r][c],dp));
        }
        dp[r][c]=res;
        return res;

    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int rows=matrix.size(),cols=matrix[0].size();
        vector<vector<int>> dp(rows,vector<int>(cols,-1));
        int LIP=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                LIP=max(LIP,dfs(matrix,i,j,INT_MIN,dp));
            }
        }
        return LIP;
    }
};
