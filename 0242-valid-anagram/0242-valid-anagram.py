class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        new_s = sorted(s)
        new_t = sorted(t)
        if(new_s==new_t):
            return True
        return False
        