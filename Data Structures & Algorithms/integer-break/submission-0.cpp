class Solution {
    int dfs(int n){
        if(n==1)return 1;
        int ans=0;
        for(int i=1;i<n;i++){
            ans=max(ans,i*max(n-i,dfs(n-i)));
        }
        return ans;
    }
public:
    int integerBreak(int n) {
        vector<int> dp(n+1,0);
        dp[0]=dp[1]=1;
        for(int i=2;i<=n;i++){
            for(int j=1;j<i;j++){
                dp[i]=max(dp[i],j*max(i-j,dp[i-j]));
            }
        }
        return dp[n];
    }
};