class Solution {
private:
    void dfs(int i, string& s, vector<string>& part,vector<vector<string>>& res, vector<vector<bool>>& dp){
        if(i>=s.length()){
            res.push_back(part);
            return;
        }
        for(int j=i;j<s.length();j++){
            if(dp[i][j]){
                part.push_back(s.substr(i,j-i+1));
                dfs(j+1,s,part,res,dp);
                part.pop_back();
            }
        }
    };
public:
    vector<vector<string>> partition(string s) {
        int n=s.size();
        vector<vector<bool>> dp(n,vector<bool>(n));
        for(int l=1;l<=n;l++){
            for(int i=0;i<=n-l;i++){
                dp[i][i+l-1]=(s[i]==s[i+l-1]&&
                              (i+1>(i+l-2)||
                              dp[i+1][i+l-2]));
            }
        }
        vector<vector<string>> res;
        vector<string> part;
        dfs(0,s,part,res,dp);
        return res;
    }
};
