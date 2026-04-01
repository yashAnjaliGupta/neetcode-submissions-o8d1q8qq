class Solution {
public:
    int findMin(vector<int> &nums) {
        int n=nums.size();
        int low=0, high=n-1,ans=nums[0];
        while(low<=high){
            if(nums[low]<nums[high]){
                ans=min(ans,nums[low]);
            }
            int mid=(low+high)/2;
            if(nums[low]<=nums[mid]){
                ans=min(ans,nums[low]);
                low=mid+1;
            }else{
                high=mid-1;
                ans=min(ans,nums[mid]);
            }
        }
        return ans;
    }
};
