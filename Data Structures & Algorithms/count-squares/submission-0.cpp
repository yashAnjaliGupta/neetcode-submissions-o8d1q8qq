class CountSquares {
    
public:
    unordered_map<int, unordered_map<int, int>> ptsCount;
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        ptsCount[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        int res=0;
        int x1=point[0],y1=point[1];

        for(auto &[y2,cnt]: ptsCount[x1]){
            int side=y2-y1;
            if(side==0)continue;

            int x3=x1+side,x4=x1-side;
            res+= cnt*ptsCount[x3][y1]*ptsCount[x3][y2];
            res+= cnt*ptsCount[x4][y1]*ptsCount[x4][y2];
        }
        return res;
    }
};
