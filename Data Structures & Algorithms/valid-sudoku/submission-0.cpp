class Solution {

public:

    struct pair_hash {
        size_t operator()(const pair<int,int>& p) const {
            return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
        }
    };

    bool isValidSudoku(vector<vector<char>>& board) {
        vector<bool> row_check(10,false);
        vector<unordered_set<int>> cols_check(9);
        unordered_map<pair<int,int>,unordered_set<int>,pair_hash> square_check;

        for(int r =0;r<9;r++){
            for(int c=0;c<9;c++){
                char n = board[r][c];
                if(n == '.') continue;
                int num = n - '0';

                if(row_check[num]){
                    return false;
                }
                row_check[num] = true;

                if(cols_check[c].count(num)){
                    return false;
                }
                cols_check[c].insert(num);

                pair<int,int> key = {r/3,c/3};
                if(square_check[key].count(num)){
                    return false;
                }
                square_check[key].insert(num);
            }
            row_check = vector<bool>(10,false);
        }

        return true;
    }
};