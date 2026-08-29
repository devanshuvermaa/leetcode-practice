class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        if (st.find(endWord) == st.end()) {
            return 0;
        }

        queue<string> q;
        q.push(beginWord);

        int level = 1;
        while (!q.empty()) {
            int sz = q.size();

            for (int i = 0; i < sz; i++) {
                string word = q.front();
                q.pop();

                if(word == endWord){
                    return level;
                }

                for (int i = 0; i < word.size(); i++) {
                    char ch = word[i];

                    for (char c = 'a'; c <= 'z'; c++) {
                        word[i] = c;
                        if (st.find(word) != st.end()) {
                            q.push(word);
                            st.erase(word);
                        }
                    }
                    word[i] = ch;
                }
            }
            level++;
        }

        return 0;
    }
};