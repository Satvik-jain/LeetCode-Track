class Solution {
public:
    bool isValid(string s) {
        if (s.length() == 1) return false; // ✅ OK: A single bracket can't be valid

        unordered_map<char, char> mpp = {
            {')', '('}, 
            {']', '['}, 
            {'}', '{'}
        }; // ✅ OK: Mapping closing to opening brackets

        stack<char> st;
        for (char c : s) {
            if (mpp.count(c)) { // ✅ Check if character is a closing bracket
                if (st.empty() || st.top() != mpp[c]) {
                    return false; // ❌ Was missing stack empty check before accessing top
                }
                st.pop(); // ✅ Valid match found — pop the top
            } else {
                st.push(c); // ✅ Only push opening brackets
            }

            // ❌ In your original code, you pushed every character (even after popping).
            // ❌ You also accessed st.top() before confirming stack wasn't empty.
            // ❌ Redundant st.push(s[i]) even after handling closing brackets.
        }

        return st.empty(); // ✅ If stack is empty, all brackets were matched correctly
    }
};
