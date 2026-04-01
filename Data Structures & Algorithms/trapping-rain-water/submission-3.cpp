class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int area=0;
        int rightGreaterValues[n]={0};
        rightGreaterValues[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            rightGreaterValues[i]=max(height[i],rightGreaterValues[i+1]);
        }
        for(int i=0;i<n;i++){
            cout<<rightGreaterValues[i]<<" ,";
        }
        cout<<endl;
        int leftGreaterValue=height[0];
        for(int i=1;i<n-1;i++){
            leftGreaterValue=max(leftGreaterValue,height[i]);
            cout<<leftGreaterValue<<"-"<<rightGreaterValues[i]<<",";
            area+= min(leftGreaterValue,rightGreaterValues[i])-height[i];
        }
        return area;


    }
};
