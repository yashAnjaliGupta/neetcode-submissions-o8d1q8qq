class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currP=nums[0],maxP=nums[0],minP=nums[0];
        for(int i=1;i<nums.size();i++){
            int tmp=maxP*nums[i];
            maxP=max(max(maxP*nums[i],minP*nums[i]),nums[i]);
            minP=min(min(minP*nums[i],tmp),nums[i]);
            cout<<maxP<<" "<<minP<<endl;
            currP=max(currP,maxP);
        }
        return currP;
    }
};
