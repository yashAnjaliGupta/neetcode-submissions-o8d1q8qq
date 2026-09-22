class Solution {
private:
    void backtrack(
        vector<vector<int>>& res,
        vector<int>& temp,
        int sum,
        vector<int>& nums, int idx,int target
    ){
        // cout<<sum<<endl;
        if(target==sum){
            res.push_back(temp);
            return;
        }
        for(int i=idx;i<nums.size();i++){
            if(i>idx && nums[i]==nums[i-1]){
                continue;
            }
            if(sum+nums[i]>target){
                break;
            }
            
            //take
            temp.push_back(nums[i]);
            backtrack(res,temp,sum+nums[i],nums,i+1,target);
            //not take
            temp.pop_back();
        }

    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector<int> temp;
        backtrack(res,temp,0,candidates,0,target);
        return res;
    }
};
