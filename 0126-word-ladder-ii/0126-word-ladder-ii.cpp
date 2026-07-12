class Solution {
public:
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> parent;

    void buildPaths(string word, string beginWord,
                    vector<string>& path) {

        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            return;
        }

        for (string &par : parent[word]) {
            path.push_back(par);
            buildPaths(par, beginWord, path);
            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(string beginWord,
                                       string endWord,
                                       vector<string>& wordList) {

        unordered_set<string> words(wordList.begin(), wordList.end());

        if (!words.count(endWord))
            return {};

        queue<string> q;
        q.push(beginWord);

        unordered_set<string> visited;
        visited.insert(beginWord);

        bool found = false;

        while (!q.empty() && !found) {

            int size = q.size();
            unordered_set<string> levelVisited;

            while (size--) {

                string word = q.front();
                q.pop();

                string original = word;

                for (int i = 0; i < word.size(); i++) {

                    char old = word[i];

                    for (char ch = 'a'; ch <= 'z'; ch++) {

                        if (ch == old)
                            continue;

                        word[i] = ch;

                        if (!words.count(word))
                            continue;

                        if (!visited.count(word)) {

                            if (!levelVisited.count(word)) {
                                q.push(word);
                                levelVisited.insert(word);
                            }

                            parent[word].push_back(original);

                            if (word == endWord)
                                found = true;
                        }
                    }

                    word[i] = old;
                }
            }

            for (auto &w : levelVisited)
                visited.insert(w);
        }

        if (!found)
            return {};

        vector<string> path;
        path.push_back(endWord);

        buildPaths(endWord, beginWord, path);

        return ans;
    }
};