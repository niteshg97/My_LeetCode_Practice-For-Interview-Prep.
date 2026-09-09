   
class Solution:

    def lastStoneWeight(self, stones: List[int]) -> int:

        heap = []

        # Python has a min-heap, so use negative weights
        for stone in stones:
            heapq.heappush(heap, -stone)

        while len(heap) > 1:

            # Get two heaviest stones
            stone1 = -heapq.heappop(heap)
            stone2 = -heapq.heappop(heap)

            # If they are different, put the difference back
            if stone1 != stone2:
                heapq.heappush(heap, -(stone1 - stone2))

        # One stone remaining, or zero stones
        if heap:
            return -heap[0]

        return 0