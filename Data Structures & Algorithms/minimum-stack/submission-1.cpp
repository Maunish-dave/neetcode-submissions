class MinStack {
public:
    vector<int> stc;
    vector<int> min_stc;
    int min_val;
    MinStack() {
        min_val = INT_MAX;
    }
    
    void push(int val) {
        stc.push_back(val);

        if(val <= min_val){
            min_stc.push_back(val);
            min_val = val;
        }
    }
    
    void pop() {

        if(stc.back()==min_val){
            min_stc.pop_back();
            min_val = (min_stc.empty()) ? INT_MAX :  min_stc.back();
        }
        stc.pop_back();
    }
    
    int top() {
        return stc.back();
    }
    
    int getMin() {
        return min_val;
    }
};
