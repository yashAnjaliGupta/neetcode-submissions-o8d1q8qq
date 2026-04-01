class Solution {
public:
    int climbStairs(int n) {
        int res=1,oneStepDown=1,twoStepsDown=1;
        for(int i=2;i<=n;i++){
            res=oneStepDown+twoStepsDown;
            twoStepsDown=oneStepDown;
            oneStepDown=res;

        }
        return res;
    }
};
