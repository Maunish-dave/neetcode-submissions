class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;

        // find the meeting point
        while(true){
            slow = nums[slow];
            fast = nums[nums[fast]];

            if(slow == fast){
                break;
            }
        }

        // find the cycle start
        int start = 0;
        while(true){
            start = nums[start];
            slow = nums[slow];
            if(start == slow){
                return start;
            }
        }

    }
};
