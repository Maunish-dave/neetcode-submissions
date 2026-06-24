class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()> s2.size()) return false;

        vector<int> count1(26,0);
        vector<int> count2(26,0);

        for(char c: s1) count1[c-'a']++;
        for(int i =0;i<s1.size()-1;i++){
            count2[s2[i]-'a']++;
        }

        int l = 0;
        for(int r = (s1.size()-1);r<s2.size();r++){
           count2[s2[r]-'a']++;

        // cout << s2[l] << " " << s2[r] << endl;
           
           bool match = true;
           for(int i =0;i<26;i++) {
              if(count1[i]!=count2[i]){
                match= false;
              }
           }
           if(match) return true;

           count2[s2[l]-'a']--;
           l++;

        }

        return false;

    }
};
