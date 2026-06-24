class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        vector<vector<int>> freq(nums.size() + 1);

        for(int n:nums){
            count[n]++;
        }

        for(auto& cnt: count){
            freq[cnt.second].push_back(cnt.first);
        }

        vector<int> res;
        for(int i = freq.size()-1; i > 0; --i){
            for(int j: freq[i]){
                res.push_back(j);
                if (res.size() == k){
                    return res;
                }
            }
        }

        return res;
    };
};
