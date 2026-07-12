class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> words(wordList.begin(), wordList.end());

        // End word must exist
        if (words.find(endWord) == words.end())
            return 0;

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        // Mark beginWord as visited if present
        words.erase(beginWord);

        while (!q.empty()) {

            auto [word, steps] = q.front();
            q.pop();

            if (word == endWord)
                return steps;

            // Try changing every character
            for (int i = 0; i < word.size(); i++) {

                char original = word[i];

                for (char ch = 'a'; ch <= 'z'; ch++) {

                    if (ch == original)
                        continue;

                    word[i] = ch;

                    if (words.find(word) != words.end()) {

                        q.push({word, steps + 1});

                        // Mark visited
                        words.erase(word);
                    }
                }

                // Restore original character
                word[i] = original;
            }
        }

        return 0;
    }
};