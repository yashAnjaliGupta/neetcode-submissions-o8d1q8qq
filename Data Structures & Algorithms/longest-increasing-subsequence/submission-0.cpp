class Solution {
private:
    int util(vector<int>& nums,int i,int j){
        if(i==nums.size()){
            return 0;
        }
        int lis=util(nums,i+1,j);
        if(j==-1||nums[j]<nums[i]){
            lis=max(lis,1+util(nums,i+1,i));
        }
        return lis;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        return util(nums,0,-1);
    }
};
