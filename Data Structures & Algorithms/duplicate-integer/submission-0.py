class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        hash_map = {}
        for i in range(len(nums)):
            num = nums[i]
            if hash_map.get(num) is not None:
                return True
            hash_map[num] = True
        
        return False