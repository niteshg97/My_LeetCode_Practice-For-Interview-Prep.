
class Solution {
public:
    vector<string> ans;
    vector<string> path;
    void solve(int idx, string &s) {
        if (path.size() == 4) {
            if (idx == s.length()) {
                string ip = "";

                for (int i = 0; i < 4; i++) {
                    if (i > 0) ip += ".";
                    ip += path[i];
                }

                ans.push_back(ip);
            }
            return;
        }
        for (int len = 1; len <= 3; len++) {

            if (idx + len > s.length())
                break;

            string segment = s.substr(idx, len);
            if (len > 1 && segment[0] == '0')
                break;
            int num = stoi(segment);

            if (num > 255)
                continue;

            // Choose
            path.push_back(segment);

            // Explore
            solve(idx + len, s);

            // Undo
            path.pop_back();
        }
    }

    vector<string> restoreIpAddresses(string s) {

        ans.clear();
        path.clear();

        if (s.length() < 4 || s.length() > 12)
            return ans;

        solve(0, s);

        return ans;
    }
};
