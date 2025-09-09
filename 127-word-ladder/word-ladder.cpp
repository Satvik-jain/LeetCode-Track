class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        if (st.count(beginWord)) st.erase(beginWord);
        if (!st.count(endWord)) return 0;
        int res = INT_MAX;
        while(!q.empty()){
            string word = q.front().first; 
            int dis = q.front().second;
            q.pop();
            for (int i =0; i < beginWord.size(); i++){
                for(int j = 0; j < 26; j++){
                    char c = 'a' + j;
                    string newWord = word; newWord[i] = c;
                    if (newWord == endWord){
                        return dis+1;
                    }
                    else if (st.count(newWord) != 0){
                        q.push({newWord, dis+1});
                        st.erase(newWord); 
                    }
                }
            }
        }
        return 0;
    }
};