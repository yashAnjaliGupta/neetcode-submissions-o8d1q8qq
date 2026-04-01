class Solution {
private:
    int robUtil(vector<int>& nums,int start,int end){
        int rob1=0;
        int rob2=0;
        int result;
        for(int i=start;i<end;i++){
            result=max(rob1,rob2+nums[i]);
            rob2=rob1;
            rob1=result;
        }
        return result;
    }
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        cout<<robUtil(nums,0,nums.size()-2);
        return max(robUtil(nums,0,nums.size()-1),robUtil(nums,1,nums.size()));
    }
};
