class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> hash;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        hash[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {

        if(hash.find(key)==hash.end()) return ""; 
        
        auto vec = hash[key];

        int l = 0;
        int r = vec.size() -1;

        string result = "";
        while(l<=r){
            int m = l + (r - l)/2;
            int val = vec[m].first;

            if (val <= timestamp){
                result =  vec[m].second;
                l = m + 1;
            }
            else{
                r = m - 1;
            }
        }

        return result;

    }
};
