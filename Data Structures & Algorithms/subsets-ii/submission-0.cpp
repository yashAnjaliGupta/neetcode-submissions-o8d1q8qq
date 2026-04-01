class Solution {
private:
    void backtrack(
        vector<vector<int>>& res,
        vector<int>& temp,
        vector<int>& nums, int idx
    ){
        // cout<<sum<<endl;
        res.push_back(temp);
        for(int i=idx;i<nums.size();i++){
            if(i>idx&&nums[i]==nums[i-1]){
                continue;
            }
    
            //take
            temp.push_back(nums[i]);
            backtrack(res,temp,nums,i+1);
            //not take
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        backtrack(res,temp,nums,0);
        return res;
    }
};
