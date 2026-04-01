class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int max_sum=nums[0],curr_sum=nums[0];
        for(int i=1;i<n;i++){
            curr_sum=max(curr_sum+nums[i],nums[i]);
            max_sum=max(max_sum,curr_sum);
        }
        return max_sum;
    }
};
