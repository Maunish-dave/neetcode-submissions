class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        hash_map = {}
        for i in s:
            if hash_map.get(i) is None:
                hash_map[i] = 1
            else:
                hash_map[i] = hash_map[i] + 1
        
        for i in t:
            present = hash_map.get(i)
            if present is None or present == 0:
                return False
            else:
                hash_map[i] -= 1

        ##check characters left 
        for j,k in hash_map.items():
            if k > 0:
                return False
            
        return True