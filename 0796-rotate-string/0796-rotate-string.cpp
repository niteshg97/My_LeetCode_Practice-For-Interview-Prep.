class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        if(s.length() != goal.length()) return false;

       string temp = s;

       for(int i = 0; i < s.length(); i++){
        rotate(temp.begin(), temp.begin()+1, temp.end());
        if(temp == goal) return true;
    }

        return false;

                
    }
};