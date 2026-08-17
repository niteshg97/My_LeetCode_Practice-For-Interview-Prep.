class Solution:
    def minWindow(self, s: str, t: str) -> str:

        if len(t) > len(s):
            return ""
        # Frequency required from t
        need = {}
        for ch in t: ## put it on the map datata structure ...
            need[ch] = 1 + need.get(ch, 0)
        # Frequency in current window
        window = {}
        l = 0
        # Number of characters whose required frequency is satisfied
        have = 0
        need_count = len(need)
        # Store best window
        res = ""
        res_len = float("inf")
        for r in range(len(s)):
            # Add s[r] to window
            ch = s[r]
            window[ch] = 1 + window.get(ch, 0)

            # If this character's required frequency is satisfied
            if ch in need and window[ch] == need[ch]:
                have += 1

            # Window is valid
            while have == need_count:
                # Update minimum window
                window_len = r - l + 1
                if window_len < res_len:
                    res_len = window_len
                    res = s[l:r + 1]
                # Remove s[l]
                left_char = s[l]
                window[left_char] -= 1
                if left_char in need and window[left_char] < need[left_char]:
                    have -= 1
                l += 1
        return res

        