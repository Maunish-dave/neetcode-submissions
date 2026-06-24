class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0;
        int rows = matrix.size();
        int cols = matrix[0].size();

        int r = (rows * cols) - 1;

        while(l<=r){
            int m = l + (r - l) /2;
            int rr = m / cols;
            int cc = m % cols;

            cout << l << " " << r << " " << m << " " << rr << " " << cc << endl;

            if(matrix[rr][cc] == target){
                return true;
            }
            if(matrix[rr][cc] > target){
                r = m - 1;
            }
            else{
                l = m + 1;
            }
        }

        return false;
    }
};
