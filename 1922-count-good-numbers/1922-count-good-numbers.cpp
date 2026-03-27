class Solution {
public:
    long long MOD = 1e9 + 7;
    long long power(long long base, long long exp) {
        if (exp == 0) return 1;

        long long half = power(base, exp / 2);

        if (exp % 2 == 0) {
            return (half * half) % MOD;
        } else {
            return (base * half % MOD * half % MOD) % MOD;
        }
    }
    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2; 
        long long odd = n / 2;  

        long long result = (power(5, even) * power(4, odd)) % MOD;

        return (int)result;
    }
};
