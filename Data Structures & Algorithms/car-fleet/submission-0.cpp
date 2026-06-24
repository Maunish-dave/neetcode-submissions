class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> pairs;

        for(int i =0;i<position.size();i++){
            pairs.push_back({position[i],speed[i]});
        }
        sort(pairs.rbegin(),pairs.rend());

        vector<double> stc;

        for(auto& pp: pairs){
            stc.push_back((double)(target-pp.first)/ pp.second);
            if(stc.size() >= 2 && stc.back() <= stc[stc.size()-2]){
                stc.pop_back();
            }
        }

        return stc.size();

    }
};
