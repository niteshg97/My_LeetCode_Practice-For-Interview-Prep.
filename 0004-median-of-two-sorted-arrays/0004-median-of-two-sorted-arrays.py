    # merge two sortd arrray , arrange in increasing order ..
    # midian is  the mid of the array 
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        #sort the  array  and merge and
        array = []
        array = nums1 + nums2
        array.sort()
        n = len(array)
        for i in range(n):
            if((n%2) == 0): # array is even
                midi = array[n//2 - 1] + array[(n//2)]
                return midi/2
            else:
                midi = array[n//2]
                return midi 

       
        

        