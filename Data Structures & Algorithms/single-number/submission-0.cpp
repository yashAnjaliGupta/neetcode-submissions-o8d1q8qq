class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xo =nums[0];
        for(int i=1;i<nums.size();i++){
            xo=xo^nums[i];
        }
        return xo;
    }
};
