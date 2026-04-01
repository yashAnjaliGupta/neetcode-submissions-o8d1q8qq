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
        vector<int> memo(n,-1);
        int maxLis=1;
        for(int i=0;i<n;i++){
            maxLis=max(maxLis,util(nums,i,memo));
        }
        return maxLis;
    }
};
