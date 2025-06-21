class Solution {
public:
//     int pos(vector<string> & v, string a){
//       for (int  i= 0; i < v.size(); i++){
//           if (v[i] == a) return i;
//       }
//       return -1;
//   }
    int ladderLength(string startWord, string targetWord,
                         vector<string>& wordList) {
        // Code here
        string a  = startWord, b = targetWord;
        unordered_set st(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        if (st.find(b) == st.end()) return 0;
        if (st.find(a) != st.end()) st.erase(a);
        q.push({a, 1});
        while(!q.empty()){
            string current = q.front().first;
            int denomination = q.front().second;
            q.pop();
            for (int i = 0; i < a.length(); i++){
                for(int j = 0; j < 26; j++){
                    string c = current;
                    c[i] = char('a' + j);
                    if (c == b) return denomination+1;
                    if (st.find(c) != st.end()){
                        st.erase(c);
                        q.push({c, denomination+1});
                    }
                }
            }
        }
        return 0;
    }
};