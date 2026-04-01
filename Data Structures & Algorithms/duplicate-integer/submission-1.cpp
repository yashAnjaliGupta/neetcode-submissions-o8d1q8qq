class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> hashMap;
        for(int i=0;i<nums.size();i++){
            if(hashMap.find(nums[i])!=hashMap.end()){
                return true;
            }
            hashMap.insert(nums[i]);
        }
        return false;
    }
};
