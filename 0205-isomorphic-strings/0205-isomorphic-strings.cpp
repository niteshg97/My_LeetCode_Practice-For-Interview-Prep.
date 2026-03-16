class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<int>s1(256,-1); // creating the two array of size = size of ASCII char..and the filling -1 , in it .
        vector<int>t1(256,-1);
        for(int i=0;i<n;i++){
            if(s1[s[i]]!=t1[t[i]]){
                return false;
            }
            s1[s[i]]=i;
            t1[t[i]]=i;
        }
        return true ;

        
    }
};