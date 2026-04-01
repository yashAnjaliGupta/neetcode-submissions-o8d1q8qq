class Solution {
private:
    int dfs(int amount,vector<int>& coins,int idx,vector<vector<int>>& dp){
        if(amount==0)return 1;
        if(idx>=coins.size())return 0;
        if(dp[idx][amount]!=-1)return dp[idx][amount];
        int res=0;
        if(amount>=coins[idx]){
            res=dfs(amount,coins,idx+1,dp);
            res+=dfs(amount-coins[idx],coins,idx,dp);
        }
        return dp[idx][amount]=res;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        sort(coins.begin(),coins.end());
        return dfs(amount,coins,0,dp);
    }
};
