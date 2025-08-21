class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> mpp;
        for (auto &w : wordList) {
            mpp[w] = 1;  
        }
        using P = pair<int, string>;
        queue<P> q;
        q.push({1, beginWord});
        mpp.erase(beginWord);
        if (mpp.find(endWord) == mpp.end()) return 0;
        while(!q.empty()){
            string curr = q.front().second;
            int len = q.front().first;
            q.pop();
            if (curr == endWord){
                return len;
            }
            for (int j = 0; j < curr.length(); j++){
                char now = curr[j];
                for (int i = 0; i < 26; i++){
                    char letter = 'a' + i;
                    if (now == letter) continue;
                    curr[j] = letter;
                    if (mpp.find(curr) != mpp.end()){
                        q.push({len+1, curr});
                        mpp.erase(curr);
                    }
                }
                curr[j] = now;
            }
        }
        return 0;;
    }
};