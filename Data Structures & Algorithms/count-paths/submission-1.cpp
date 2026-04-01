class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> row(n,1);
        for(int i=1;i<m;i++){
            vector<int> newRow(n,1);
            for(int j=1;j<n;j++){
                newRow[j]=newRow[j-1]+row[j];
            }
            row=newRow;
        }
        return row[n-1];
    }
};
