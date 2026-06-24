class Solution {
public:
    int eval(string a, string b, string opr){
        if(opr== "+"){
            return stoi(a) + stoi(b);
        }
        else if(opr == "-")
        {
            return stoi(a) - stoi(b);
        } 
        else if(opr == "*")
        {
            return stoi(a) * stoi(b);
        }  
        else if(opr == "/"){
            return stoi(a) / stoi(b);
        }
        return 0;
    }

    int evalRPN(vector<string>& tokens) {
        stack<string> stc;
        set<string> is_op = {"+","-","*","/"};
        int val = INT_MAX;

        for(string s: tokens){
            if(is_op.count(s)){
                string second_val = stc.top();
                stc.pop();
                string first_val = stc.top();
                stc.pop();

                int val = eval(first_val,second_val,s);
                stc.push(to_string(val)); 
            }
            else{
                stc.push(s);
            }
        }

        return stoi(stc.top());
    }
};
