class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;

        return (n & (long long)n - 1) == 0;
        
    }
};