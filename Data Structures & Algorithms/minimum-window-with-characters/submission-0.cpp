class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        if (t.empty() || n == 0) return "";

        int min_l = 0, min_len = INT_MAX;
        int r = 0, l = 0;

        vector<int> count1(128, 0);
        for (char c : t) count1[c]++;

        while (r <= n) {
            // rebuild count2 for current window [l, r)
            vector<int> count2(128, 0);
            for (int i = l; i < r; i++) count2[s[i]]++;

            // window matches if it contains AT LEAST every char of t
            bool count_match = true;
            for (int i = 0; i < 128; i++) {
                if (count2[i] < count1[i]) { count_match = false; break; }
            }

            if (count_match) {
                if (r - l < min_len) {
                    min_len = r - l;
                    min_l = l;
                }
                l++;            // try to shrink
            } else {
                if (r == n) break;   // can't expand, can't match -> done
                r++;                 // expand
            }
        }

        return min_len == INT_MAX ? "" : s.substr(min_l, min_len);
    }
};