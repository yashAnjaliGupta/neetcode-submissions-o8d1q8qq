class Solution {
private:
    void backtrack(vector<vector<int>>& res,
        vector<int>& temp,
        int sum,int target,vector<int>& nums,int idx){
        if(sum==target){
            res.push_back(temp);
            return;
        }
        if(sum > target || idx>=nums.size()){
            return;
        }
        
        //take 
        temp.push_back(nums[idx]);
        backtrack(res,temp,sum+nums[idx],target,nums,idx);
        //not take
        temp.pop_back();
        backtrack(res,temp,sum,target,nums,idx+1);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        int sum=0;
        backtrack(res,temp,sum,target,nums,0);
        return res;
    }
};
