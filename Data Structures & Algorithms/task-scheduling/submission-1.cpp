class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26,0);
        for(int i=0;i<tasks.size();i++){
            count[tasks[i]-'A']++;
        }
        int maxFreq= *max_element(count.begin(),count.end());
        int maxCount=0;
        for(int i:count){
            if(i==maxFreq)maxCount++;
        }
        int time=(maxFreq-1)*(n+1)+maxCount;
        return max((int)tasks.size(),time);
    }
};
