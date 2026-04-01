class Solution {
int Util(int amount,vector<int>& coins,unordered_map<int, int>& memoization){
    if(amount==0) return 0;
    if(memoization.find(amount)!=memoization.end()){
        return memoization[amount];
    }
    int res = 100000000;
    for(int i=0;i<coins.size();i++){
        if(amount>=coins[i]){
            int result=Util(amount-coins[i],coins,memoization);
            if(result<100000000)
                res=min(res,1+result);
        }
    }
    return memoization[amount]=res;
}
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        unordered_map<int, int> memoization;
        int minCoins=Util(amount,coins,memoization);
        return minCoins<100000000?minCoins:-1;
    }
};
