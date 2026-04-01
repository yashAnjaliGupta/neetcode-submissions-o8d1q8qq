class Solution {
public:
    int n=9;

    bool isValidSudoku(vector<vector<char>>& board) {
        // cout<< 'a';
        for(int i=0;i<n;i++){
            unordered_map<char,int> mp;
            for(int j=0;j<n;j++){
                char temp=board[i][j];
                if(temp!='.'){
                    mp[temp]++;
                    if(mp[temp]>1){
                        // cout<< i<<" "<<j;
                        return false;
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            unordered_map<char,int> mp;
            for(int j=0;j<n;j++){
                char temp=board[j][i];
                if(temp!='.'){
                    mp[temp]++;
                    if(mp[temp]>1){
                        // cout<< i<<" "<<j;
                        return false;
                    }
                }
            }
        }
        for(int i=0;i<n;i+=3){
            for(int j=0;j<n;j+=3){
                unordered_map<char,int> mp;
                for(int k=i;k<i+3;k++){
                    for(int l=j;l<j+3;l++){
                        char temp=board[k][l];
                        if(temp!='.'){
                            mp[temp]++;
                            if(mp[temp]>1){
                                // cout<< k<<" "<<l;
                                return false;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};
