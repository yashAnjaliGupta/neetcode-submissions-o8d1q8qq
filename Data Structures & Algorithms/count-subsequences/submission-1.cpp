class Solution {
private:
    int dfs(string s,string t,int i,int j){
        if(j<0)return 1;
        if(i<0)return 0;
        
        //match
        int res=0;
        if(s[i]==t[j])res+=dfs(s,t,i-1,j-1);
        res+=dfs(s,t,i-1,j);

        return res;


    }
public:
    int numDistinct(string s, string t) {
        int n=s.length(),m=t.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                dp[i][j]+=dp[i-1][j];
                if(s[i-1]==t[j-1]){
                    dp[i][j]+=dp[i-1][j-1];
                }
            }
        }
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                cout<<dp[i][j]<<", ";
            }
            cout<<endl;
        }
        return dp[n][m];
    }
};
