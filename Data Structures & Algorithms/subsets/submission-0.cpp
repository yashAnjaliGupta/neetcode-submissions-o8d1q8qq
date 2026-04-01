class Solution {
private:
    void backtrack(vector<vector<int>> &res,vector<int> &temp,int idx,vector<int>& nums){
        if(idx==nums.size()){
            res.push_back(temp);
            return;
        }
        //not take
        backtrack(res,temp,idx+1,nums);
        //take
        temp.push_back(nums[idx]);
        backtrack(res,temp,idx+1,nums);
        temp.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        backtrack(res,temp,0,nums);
        return res;
    }
};
