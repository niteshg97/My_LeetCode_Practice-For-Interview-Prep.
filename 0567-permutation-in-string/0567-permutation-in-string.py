class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        # If s1 is longer, permutation cannot exist
        if len(s1) > len(s2):
            return False
        count1 = {}
        count2 = {}
        # Frequency of characters in s1
        for i in range(len(s1)):
            count1[s1[i]] = 1 + count1.get(s1[i], 0)
        # First window of s2
        l = 0
        for r in range(len(s1)):
            count2[s2[r]] = 1 + count2.get(s2[r], 0)
        # Check first window
        if count1 == count2:
            return True
        # Slide the window
        for r in range(len(s1), len(s2)):
            # Add new character entering the window
            count2[s2[r]] = 1 + count2.get(s2[r], 0)
            # Remove character leaving the window
            count2[s2[l]] -= 1
            # Remove key if frequency becomes 0
            if count2[s2[l]] == 0:
                del count2[s2[l]]
            l += 1
            # Check current window
            if count1 == count2:
                return True
        return False
        