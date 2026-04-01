class Solution {
private:
    bool util(vector<int>& nums,int idx,int target,vector<vector<int>> memo){
        if(idx==nums.size())return target==0;
        if(target<0)return false;
        if(memo[idx][target]!=-1){
            return memo[idx][target];
        }
        // memo[idx+1][target-nums[idx]]= util(nums,idx+1,target-nums[idx],memo);
        // memo[idx+1][target]= util(nums,idx+1,target,memo);
        return memo[idx][target]= util(nums,idx+1,target-nums[idx],memo)|| util(nums,idx+1,target,memo);
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum=0,n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2==1){
            return false;
        }
        vector<vector<int>> memo(n+1,vector<int>(sum/2+1,-1));
        return util(nums,0,sum/2,memo);

    }
};
