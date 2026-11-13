
class Solution:
    def restoreIpAddresses(self, s: str) -> list[str]:
        res = []
        path = []

        def backtrack(idx):
            if len(path) == 4:
                if idx == len(s):
                    res.append(".".join(path))
                return

            for length in range(1, 4):

                if idx + length > len(s):
                    break
                segment = s[idx:idx + length]
                if len(segment) > 1 and segment[0] == '0':
                    break
                if int(segment) > 255:
                    continue
                path.append(segment)
                backtrack(idx + length)
                path.pop()
        backtrack(0)

        return res

        