class MedianFinder:

    def __init__(self):
        self.max_heap = [] #left part of num will store
        self.min_heap = [] #right part of num will store

    def addNum(self, num: int) -> None:
        heapq.heappush(self.max_heap , -num) # put num in max heap 
        largest_small = -heapq.heappop(self.max_heap)
        heapq.heappush(self.min_heap , largest_small)
        if(len(self.min_heap) > len(self.max_heap)):
            smallest_large = heapq.heappop(self.min_heap)
            heapq.heappush(self.max_heap , -smallest_large)

    def findMedian(self) -> float:
        if(len(self.max_heap) > len(self.min_heap)):
            return  -self.max_heap[0]
        else:
            small = -self.max_heap[0]
            large = self.min_heap[0]
        return (small + large) / 2
        
# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()