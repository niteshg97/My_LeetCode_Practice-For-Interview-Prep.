class Solution {
public:
    string reverseWords(string s) {

        reverse(s.begin(), s.end());

        int n = s.size();
        int i = 0, l = 0, r = 0;

        while(i < n){

            while(i < n && s[i] == ' ') i++;
            if(i == n) break;

            if(l != 0) s[l++] = ' ';

            r = i;
            while(r < n && s[r] != ' ') r++;

            reverse(s.begin() + i, s.begin() + r);

            while(i < r)
                s[l++] = s[i++];

            i = r;
        }

        s.resize(l);
        return s;
    }
};
