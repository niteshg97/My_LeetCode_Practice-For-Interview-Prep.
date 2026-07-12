class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<vector<string>> ans;

        if (!dict.count(endWord)) return ans;

        unordered_map<string, vector<string>> parent;
        unordered_set<string> cur{beginWord};
        bool found = false;

        while (!cur.empty() && !found) {
            for (auto &w : cur) dict.erase(w);

            unordered_set<string> nxt;

            for (auto word : cur) {
                string s = word;

                for (int i = 0; i < s.size(); i++) {
                    char old = s[i];

                    for (char c = 'a'; c <= 'z'; c++) {
                        s[i] = c;

                        if (!dict.count(s)) continue;

                        nxt.insert(s);
                        parent[s].push_back(word);

                        if (s == endWord) found = true;
                    }

                    s[i] = old;
                }
            }

            cur = move(nxt);
        }

        if (!found) return ans;

        vector<string> path{endWord};

        function<void(string)> dfs = [&](string word) {
            if (word == beginWord) {
                vector<string> temp = path;
                reverse(temp.begin(), temp.end());
                ans.push_back(temp);
                return;
            }

            for (auto &p : parent[word]) {
                path.push_back(p);
                dfs(p);
                path.pop_back();
            }
        };

        dfs(endWord);
        return ans;
    }
};