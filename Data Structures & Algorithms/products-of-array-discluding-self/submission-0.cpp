class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector <long long int> rightProduct(n+1,1);
        // rightproduct[n-1]=nums[i];
        for(int i=nums.size()-1;i>0;i--){
            rightProduct[i-1]=nums[i]*rightProduct[i];
        }
        long long int product=1;
        vector<int> ans(n,1);
        for(int i=0;i<n;i++){
            ans[i]=product*rightProduct[i];
            product*=nums[i];
        }
        return ans;
    }
};
