class Solution {
private:
    int binarySearch(vector<int>& nums, int target,int start,int end){
        if(start<end){
            int mid=(start+end)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(target<nums[mid]){
                return binarySearch(nums,target,start,mid);
            }
            return binarySearch(nums,target,mid+1,end);
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        return binarySearch(nums,target,0,nums.size());
        
    }
};
