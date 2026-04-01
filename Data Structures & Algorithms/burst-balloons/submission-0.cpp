class Solution {
private:
    int dfs(vector<int>& nums,int l,int r,vector<vector<int>>& dp){
        if(l>r)return 0;
        if(dp[l][r]!=-1)return dp[l][r];

        dp[l][r]=0;
        for(int i=l;i<=r;i++){
            int coins=nums[l-1]*nums[i]*nums[r+1];
            coins+= dfs(nums,l,i-1,dp)+dfs(nums,i+1,r,dp);
            dp[l][r]=max(dp[l][r],coins);
        }
        return dp[l][r];
    }
public:
    int maxCoins(vector<int>& nums) {
        int n= nums.size();
        vector<int> newNums(n+2,1);
        for(int i=0;i<n;i++){
            newNums[i+1]=nums[i];
        }
        vector<vector<int>> dp(n+2,vector<int>(n+2,-1));
        return dfs(newNums,1,newNums.size()-2,dp);
    }
};
