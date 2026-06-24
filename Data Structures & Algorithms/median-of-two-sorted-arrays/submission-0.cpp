class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        int half = (total + 1) / 2;

        vector<int> & A = nums1;
        vector<int> & B = nums2;

        if(B.size() < A.size()){
            swap(A,B);
        }

        int l = 0;
        int r = A.size();

        while(l <= r){
            int ma = (l + r) /2;
            int mb = half - ma;


            int Aleft = ma > 0 ? A[ma-1] : INT_MIN;
            int Aright = ma < A.size() ? A[ma] : INT_MAX;
            int Bleft = mb > 0 ? B[mb-1] : INT_MIN;
            int Bright = mb < B.size() ? B[mb] : INT_MAX;

            if (Aleft <= Bright && Bleft <= Aright){
                if (total %2 !=0){
                    return max(Aleft,Bleft);
                }
            return (max(Aleft,Bleft) + min(Aright,Bright)) / 2.0;
            }
            else if (Aleft > Bright){
                r = ma -1;
            } else{
                l = ma + 1;
            }

        }

        return -1;
        

    }
};
