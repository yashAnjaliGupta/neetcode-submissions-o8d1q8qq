class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> leftSmaller(n,-1),rightSmaller(n,n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty()&& heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(!st.empty()){
                leftSmaller[i]=st.top();
            }
            st.push(i);
        }
        while(!st.empty())st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&& heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(!st.empty()){
                rightSmaller[i]=st.top();
            }
            st.push(i);
        }
        int maxArea;
        for(int i=0;i<n;i++){
            leftSmaller[i]++;
            rightSmaller[i]--;
            maxArea=max(maxArea,heights[i]*(rightSmaller[i]-leftSmaller[i]+1));
        }
        return maxArea;
    }
};
