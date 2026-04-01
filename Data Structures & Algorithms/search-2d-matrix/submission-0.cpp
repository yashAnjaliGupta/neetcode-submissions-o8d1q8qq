class Solution {
private:
    bool binarySearch(vector<int>& row,int target,int start,int end){
        if(start<=end){
            int mid=(start+end)/2;
            if(row[mid]==target)return true;
            if(row[mid]<target) return binarySearch(row,target,mid+1,end);
            return binarySearch(row,target,start,mid-1);
        }
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size();
        int start=0,end=n-1;
        int row=-1;
        while(start<=end){
            int mid=(start+end)/2;
            if(target>=matrix[mid][0] && target<=matrix[mid][m-1]){
                row=mid;
                break;
            }
            if(target>matrix[mid][m-1]){
                start=mid+1;
            }else if(target< matrix[mid][0]){
                end=mid-1;
            }
        }
        if(row==-1)return false;
        return binarySearch(matrix[row],target,0,m-1);
    }
};
