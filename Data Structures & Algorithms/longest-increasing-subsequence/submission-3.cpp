class Solution {
private:
    int util(vector<int>& nums,int i,vector<int>& memo){
        if(memo[i]!=-1){
            return memo[i];
        }
        int lis=1;
        for(int j=i+1;j<nums.size();j++){
            if(nums[i]<nums[j]){
                lis=max(lis,1+util(nums,j,memo));
            }
        }
        return memo[i]=lis;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;--i){
            for(int j=i-1;j>=-1;--j){
                int lis=dp[i+1][j+1];
                if(j==-1||nums[j]<nums[i]){
                    lis=max(lis,1+dp[i+1][i+1]);
                }
                dp[i][j+1]=lis;
            }
        }
        return dp[0][0];
    }
};
