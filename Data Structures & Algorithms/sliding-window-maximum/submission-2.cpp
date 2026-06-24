class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int l =0,r = 0;
        priority_queue<pair<int,int>> pq;
        int n = nums.size();

        // fill the priority queue till window size
        while(r<k){
            pq.push({nums[r],r});
            r++;
        }
        res.push_back(pq.top().first);
        l++;

        while(r < n){
            pq.push({nums[r],r});
            while(pq.top().second < l){
                pq.pop();
            }
            res.push_back(pq.top().first);
            r++;
            l++;
        }

        return res;
    }
};
