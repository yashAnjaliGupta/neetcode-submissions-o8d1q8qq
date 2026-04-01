class Solution {
public:
    bool canJump(vector<int>& nums) {
        // if(nums.size()==1)return true;
        int goal=nums.size();
        int maxStep=0;
        for(int i=0;i<goal;i++){
            if(i+nums[i]>=maxStep){
                maxStep=i+nums[i];
            }
            if(maxStep>=goal-1)return true;
            if(maxStep<=i){
                return false;
            }
            cout<<maxStep<<" "<<i<<endl;
        }
        return maxStep==goal-1;
    }
};
