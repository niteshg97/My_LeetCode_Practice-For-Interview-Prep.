class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        # Frequency map
        mp = {}
        for num in nums:
            mp[num] = mp.get(num, 0) + 1
        # Min heap: (frequency, element)
        hp = []
        for element, freq in mp.items():
            heapq.heappush(hp, (freq, element))
            # Keep only k elements
            if len(hp) > k:
                heapq.heappop(hp)
        # Extract elements
        ans = []
        while hp:
            freq, element = heapq.heappop(hp)
            ans.append(element)
        return ans
        

                

        