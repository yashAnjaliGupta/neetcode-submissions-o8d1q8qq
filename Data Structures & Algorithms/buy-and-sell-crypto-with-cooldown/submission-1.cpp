class Solution {
private:
    int dfs(vector<int>& prices,int i,bool canBuy){
        if(i>=prices.size())return 0;
        int nothing=dfs(prices,i+1,canBuy);
        //if puchased
        if(canBuy){
            return max(nothing,dfs(prices,i+1,false)-prices[i]);
        }//sold
        else{
            return max(nothing,prices[i]+dfs(prices,i+2,true));
        }
    }


public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        return dfs(prices,0,true);
    }
};
