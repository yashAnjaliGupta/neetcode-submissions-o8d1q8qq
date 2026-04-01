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
        vector<int> dp(n+1,1);
        for(int i=n-1;i>=0;--i){
            for(int j=i+1;j<n;j++){
                if(nums[i]<nums[j]){
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};
