class Solution {
private:
    bool check(vector<int>& piles,int h,int k){
        int hours=0;
        for(int i=0;i<piles.size();i++){
            hours+=ceil((double)piles[i]/k);
        }
        return hours<=h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxBananas= *max_element(piles.begin(),piles.end());
        int minSpeed=1,maxSpeed=maxBananas;
        int res=maxSpeed;
        while(minSpeed<maxSpeed){
            int k=(minSpeed+maxSpeed)/2;
            if(check(piles,h,k)){
                maxSpeed=k;
            }
            else{
                minSpeed=k+1;
            }
        }
        return minSpeed;
    }
};
