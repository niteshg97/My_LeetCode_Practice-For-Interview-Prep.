class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        heap = [] # Min Heap to store the top smallest elements..
        for x , y in points:
            d = x*x + y*y
            heapq.heappush(heap , (-d , [x, y])) # -d to push the min elements from the heap 
        
            if (len(heap) > k):
                heapq.heappop(heap)
    
        return [p for d , p in heap]
            
        