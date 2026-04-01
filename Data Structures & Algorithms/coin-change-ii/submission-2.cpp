class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1,0);
        dp[0]=1;
        for(int j=0;j<coins.size();j++){
            for(int i=0;i<=amount;i++){
                if(i-coins[j]>=0){
                    dp[i]+=dp[i-coins[j]];
                }
            }
        }
        for(int i=0;i<=amount;i++){
            cout<<dp[i]<<" ";
        }
        return dp[amount];
    }
};
