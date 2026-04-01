class Solution {
private:
    int util(vector<int>& nums,int i,int j,vector<vector<int>>& memo){
        if(i==nums.size()){
            return memo[i][j+1]=0;
        }
        if(memo[i][j+1]!=-1)return memo[i][j+1];
        int lis=util(nums,i+1,j,memo);
        if(j==-1||nums[j]<nums[i]){
            lis=max(lis,1+util(nums,i+1,i,memo));
        }
        return memo[i][j+1]=lis;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> memo(nums.size()+1,vector<int>(nums.size()+1,-1));
        return util(nums,0,-1,memo);
    }
};
