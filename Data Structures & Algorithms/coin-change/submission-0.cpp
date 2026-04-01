class Solution {
int Util(int idx,int target,vector<int>& coins){
    if(idx==0){
        if(target%coins[idx]==0)return target/coins[idx];
        return 100000000;
    }
    int notTake= Util(idx-1,target,coins);
    int take=100000000;
    if(target>=coins[idx])
        take = Util(idx,target-coins[idx],coins)+1;
    return min(notTake,take);
}
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        int minCoins=Util(n-1,amount,coins);
        if(minCoins>=100000000)return -1;
        return minCoins;
    }
};
