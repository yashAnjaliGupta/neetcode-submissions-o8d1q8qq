class Solution {
private:
    double recurPow(double x,int n){
        if(n==1) return x;
        if(n==0)return 1;
        double temp=recurPow(x,n/2);
        if(n&1)return x*temp*temp;
        return temp*temp;
    }
public:
    double myPow(double x, int n) {
        double ans=recurPow(x,abs(n));
        return n>0?ans:1/ans;
    }
};
