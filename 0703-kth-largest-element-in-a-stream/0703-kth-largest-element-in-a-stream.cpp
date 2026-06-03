class KthLargest {
public:
    priority_queue<int,vector<int> , greater<int>>pq; 
    int K;
    KthLargest(int k, vector<int>& nums) {
        int n = nums.size();
        K=k;
        // put all the elements in pq
        for(int i=0;i<n;i++){
            pq.push(nums[i]);
            if(pq.size()>k){
                pq.pop() ;// top element (jo smallest hoga) uskon uda do
            }
        }
    }
    int add(int val) {
        pq.push(val);
        if(pq.size()>K){
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */