class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.k = k
        self.heap = []
        for num in nums:
            heapq.heappush(self.heap , num) # heap me nums ka elelmnets daal do
            if(len(self.heap) > k):
                heapq.heappop(self.heap) # agar heap me k se jyada element hai to pop kr do .... heap me bss k elements hi rakhna hai 

    def add(self, val: int) -> int:
        heapq.heappush(self.heap, val) # jb new element aa raha ho to heap me dsal do 
        if(len(self.heap) > self.k):
            heapq.heappop(self.heap)
        return self.heap[0]

        


# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)