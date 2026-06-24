class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int,int> count; 
        int res = 0;
        int l  = 0;
        int max_c = 0;
        for(int r=0;r<s.size();r++){
            count[s[r]]++;
            max_c = max(max_c, count[s[r]]);

            if((r-l) + 1 - max_c > k){
                count[s[l]]--;
                l++;
            }

            res = max(res, (r-l)+1);
        }

        return res;
    }
};
