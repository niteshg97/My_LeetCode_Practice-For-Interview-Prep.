class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend==divisor) return 1;
        bool sign = true;
        if(dividend>=0 && divisor<0){
            sign =false;
        }
        if(dividend<0 && divisor>0){
            sign =false;
        }

        long long ans=0;
        long long n =abs((long long )dividend);
        long long d=abs((long long) divisor);
        while(n>=d){
            int count=0;
            while(n>=(d<<(count+1))){ // d<<(count+1)= d*2^count+1
                count ++;
                
            }
            ans += (1LL << count);  //(1<<count)=2^count
            n -= (d << count); 
         
        }
        if (ans > INT_MAX && sign) return INT_MAX;
        return sign ? (int)ans : (int)(-ans);
 
    }
};