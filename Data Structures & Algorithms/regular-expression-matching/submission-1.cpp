class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.length(),m=p.length();
        vector<vector<int>> dp(n+1,vector<int> (m+1));
        dp[0][0]=true;
        for(int j=2;j<=m;j++){
            if(p[j-1]=='*')dp[0][j]=dp[0][j-2];
        }
        // Fill DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (p[j - 1] == s[i - 1] || p[j - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2] || (dp[i - 1][j] && 
                                  (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
                }
            }
        }
        return dp[n][m];
    }
};