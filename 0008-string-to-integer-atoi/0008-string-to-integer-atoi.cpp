class Solution {
public:
    int myAtoi(string s) {
        int n=s.size();
        set<int>st;
        int i=0;
        // skip spaces 
        while (i < n && s[i] == ' ') i++;
       // handle Sign 
       int sign =1;
       if(i<n && (s[i]=='+' || s[i]=='-')){
        if(s[i]=='-') sign = -1;
        i++;
       }
       // str to number 
       long result=0;
       while(i<n && isdigit(s[i])){
        int digit=s[i]-'0';
        // overflow check

        if (result > (INT_MAX - digit) / 10) {
            return (sign == 1) ? INT_MAX : INT_MIN;

          }

        result=result*10 +digit;
        i++;
       }
       return sign*result;
       
        
    }
};