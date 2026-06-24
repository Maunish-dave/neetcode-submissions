class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> arr1(n); // forward pass
        vector<int> arr2(n); // backward pass

        arr1[0] = nums[0];
        arr2[n-1] = nums[n-1];

        for(int i =1;i<n;i++){ // forward pass 
            arr1[i] = (nums[i] * arr1[i-1]);
        }


        // backward pass
        for(int i =n-2;i>=0;i--){
            arr2[i] = nums[i] * arr2[i+1];
        }

        vector<int> res(n);

        for(int i = 0;i<n;i++){
            res[i] = ((i>0) ? arr1[i-1] : 1)  * ((i<n-1) ? arr2[i+1] : 1);
        }

        return res;
    }
};
