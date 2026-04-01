class Solution {
public:
    int recRob(int idx,vector<int>& nums,vector<int>& memorized){
        if(idx<0)return 0;
        if(memorized[idx]!=-1)return memorized[idx];
        int left=recRob(idx-2,nums,memorized)+nums[idx];
        int right = recRob(idx-1,nums,memorized);
        memorized[idx]= max(left,right);
        return memorized[idx];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>memorized(n,-1);
        return recRob(n-1,nums,memorized);
    }
};
