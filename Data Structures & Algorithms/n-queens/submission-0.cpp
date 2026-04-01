class Solution {
private: 
 void backtrack(int r,vector<string>& res,int n,
 vector<bool>& columnStatus,
        vector<bool> TDDiagStatus,vector<bool>& DTDiagStatus,vector<vector<string>>& ans){

            if(r>=n){
                ans.push_back(res);
                return;
            }
            for(int j=0;j<n;j++){
                if(columnStatus[j]||TDDiagStatus[r+j]||DTDiagStatus[n-1-(r-j)])continue;
                columnStatus[j]=true;
                TDDiagStatus[r+j]=true;
                DTDiagStatus[n-1-(r-j)]=true;
                res[r][j]='Q';
                backtrack(r+1,res,n,columnStatus,TDDiagStatus,DTDiagStatus,ans);
                columnStatus[j]=false;
                TDDiagStatus[r+j]=false;
                DTDiagStatus[n-1-(r-j)]=false;
                res[r][j]='.';
            }
        }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<bool> columnStatus(n,false);
        vector<bool> TDDiagStatus(2*n-1,false),DTDiagStatus(2*n-1,false);
        vector<vector<string>> ans;
        vector<string> res(n,string(n,'.'));
        backtrack(0,res,n,columnStatus,TDDiagStatus,DTDiagStatus,ans);
        return ans;
    }
};
