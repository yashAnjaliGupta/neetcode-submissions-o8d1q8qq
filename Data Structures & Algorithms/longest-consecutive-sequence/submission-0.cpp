class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set <int> hashMap(nums.begin(),nums.end());
        int longestSequenceLength=0,currentSequenceLength=0;
        for(int i=0;i<nums.size();i++){
            if(hashMap.find(nums[i]-1)==hashMap.end()){
                currentSequenceLength=0;
                int temp=nums[i];
                while(hashMap.find(temp)!=hashMap.end()){
                    temp++;
                    currentSequenceLength++;
                }
                longestSequenceLength=max(longestSequenceLength,currentSequenceLength);
            }
        }
        return longestSequenceLength;
    }
};
