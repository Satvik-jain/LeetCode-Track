class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1) return strs[0];
        string ans = "";
        int index = 0;
        while(true){
            if(index > strs[0].length()) return strs[0];
            char c = strs[0][index];
            for (int i = 1; i < strs.size(); i++){
                if (index>strs[i].length()) return strs[i];
                if (c == strs[i][index]) continue;
                else{
                    return (ans!="")? ans:"";
                }
            }
            ans+=c;
            index++;
        }
        // return ans;
    }
};