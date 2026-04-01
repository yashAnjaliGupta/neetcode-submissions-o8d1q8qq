class Solution {
public:
    int climbStairs(int n) {
        int ans=1;
        int prev=1;
        for(int i=1;i<n;i++){
            int temp=ans+prev;
            prev=ans;
            ans=temp;
        }
        return ans;
    }
};
