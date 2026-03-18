class Solution {
public:
    int maxDepth(string s) {
        int n=s.size();
        int currentDepth =0;
        int maxDepth=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                currentDepth++;
                maxDepth=max(maxDepth,currentDepth);
            
            }
            else if(s[i]==')'){
                currentDepth--;
            }

        }
        return maxDepth;
        
    }
};