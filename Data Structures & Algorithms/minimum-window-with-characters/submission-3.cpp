class Solution {
public:
    string minWindow(string s, string t) {

        if (t.empty()) return "";
        
        unordered_map<char,int> countInT, countInWindow;

        // fill countInT
        for(char c:t) countInT[c]++;
        int have = 0, need = countInT.size();

        int l =0;
        vector<int> res = {-1,-1};
        int min_len = INT_MAX;

        for(int r = 0;r<s.size();r++){
            // add it into the window
            char c = s[r];
            countInWindow[c]++;

            // check if count satifies
            if (countInT.count(s[r]) && countInT[c] == countInWindow[c]){
                have++;
            }

            while(have==need){
                if ((r-l+1) < min_len){
                    min_len = r - l + 1;
                    res = {l, r};
                }

                countInWindow[s[l]]--;
                if(countInT.count(s[l]) && countInWindow[s[l]] < countInT[s[l]]){
                    have--;
                }
                l++;
            }
        }

        return min_len == INT_MAX ? "" : s.substr(res[0],min_len);

    }
};
