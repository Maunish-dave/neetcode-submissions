class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        prevdiff = {}

        for i, n in enumerate(nums):
            diff = target - n 
            if diff in prevdiff:
                return [prevdiff[diff], i]
            prevdiff[n] = i
