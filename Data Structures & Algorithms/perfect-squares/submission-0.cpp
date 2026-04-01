class Solution {
public:
    int numSquares(int n) {
        vector <int> dp(n+1,10000);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j*j<=i;j++){
                if(i-j*j==0)dp[i]=1;
                else
                dp[i]=min(dp[i-j*j]+dp[j*j],dp[i]);
            }
        }
        for(int i=1;i<=n;i++){
            cout<<dp[i]<<", ";
        }
        return dp[n];
    }
};