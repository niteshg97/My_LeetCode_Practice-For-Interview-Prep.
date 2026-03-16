class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        int m =goal.size();
        if(n!=m){
            return false;
        }
        for(int i=0;i<n;i++){
            char first=s[0];
            string rest=s.substr(1);
            s=rest+first;
            if(s==goal){
            return true ;
            }
        }

        return false ;
                
    }
};