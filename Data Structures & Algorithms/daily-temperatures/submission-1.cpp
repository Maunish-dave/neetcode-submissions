class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n,0);
        stack<int> stc;

        for(int i = 0;i<n;i++){
            int val = temperatures[i];

            while(!stc.empty() && val > temperatures[stc.top()]){
                int top_index = stc.top();
                res[top_index] = (i - top_index);
                stc.pop();
            }
            stc.push(i);
        }

        return res;
    }
};
