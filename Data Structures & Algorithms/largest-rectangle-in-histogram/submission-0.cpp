class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> leftMost(n,-1);
        vector<int> rightMost(n,n);
        stack<int> stc;

        for(int i =0;i<n;i++){
            while(!stc.empty() && heights[stc.top()] >= heights[i]){
                stc.pop();
            }
            if(!stc.empty()){
                leftMost[i] = stc.top();
            }
            stc.push(i);
        }

        while(!stc.empty()) {stc.pop();}

        for(int i = n-1;i >= 0;i--){
            while(!stc.empty() && heights[stc.top()] >= heights[i]){
                stc.pop();
            }
            if(!stc.empty()){
                rightMost[i] = stc.top();
            }            
            stc.push(i);
        }

        int answer = 0;
        for(int i =0;i<n;i++){
            leftMost[i] += 1;
            rightMost[i] -=1;
            answer = max(answer,heights[i] * (rightMost[i] - leftMost[i] + 1));
        }

        return answer;
    }
};
