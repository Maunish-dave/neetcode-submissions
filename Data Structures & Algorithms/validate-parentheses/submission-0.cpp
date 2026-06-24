class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> open;
        open[']'] = '[';
        open[')'] = '(';
        open['}'] = '{';

        stack<char> stc;

        for(char c: s){
            if (!open.count(c)){ // open bracket
                stc.push(c);
                cout << c << endl;
            }
            else{
                if(stc.empty() || open[c] != stc.top()){
                    return false;
                }
                stc.pop();
            }
        }

        return stc.empty();
    }
};
