class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sumGas=0,sumCost=0;
        for(int i=0;i<gas.size();i++){
            sumGas+=gas[i];
            sumCost+=cost[i];
        }
        if(sumGas<sumCost)return -1;

        int total=0,res=0;
        for(int i=0;i<gas.size();i++){
            total+=(gas[i]-cost[i]);
            if(total<0){
                total=0;
                res=i+1;
            }
        }
        return res;
    }
};
