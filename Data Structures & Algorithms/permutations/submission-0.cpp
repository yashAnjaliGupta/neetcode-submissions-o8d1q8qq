class Solution {
private:
 void backtrack(int idx,vector<int>& nums,vector<vector<int>> &res,
        vector<int> &temp){
            if(idx==nums.size()){
                res.push_back(nums);
            }
        for(int i=idx;i<nums.size();i++){
            swap(nums[idx],nums[i]);
            backtrack(idx+1,nums,res,temp);
            swap(nums[idx],nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        backtrack(0,nums,res,temp);
        return res;
    }
};
