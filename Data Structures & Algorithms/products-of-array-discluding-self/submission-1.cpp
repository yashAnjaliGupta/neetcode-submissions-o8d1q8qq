class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int numsSize=nums.size();
        vector<int> rightSideProduct(numsSize+1,1);
        for(int i=numsSize-2;i>=0;i--){
            rightSideProduct[i]=nums[i+1]*rightSideProduct[i+1];
        }
        int leftHandProduct=1;
        vector<int> products(numsSize,1);
        for(int i=0;i<numsSize;i++){
            products[i]=leftHandProduct*rightSideProduct[i];
            leftHandProduct*=nums[i];
        }
        return products;
    }
};
