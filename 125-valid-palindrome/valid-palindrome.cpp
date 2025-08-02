class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        while (j > i) {
            // Skip non-alphanumeric characters
            if (!isalnum(s[i])) {
                i++;
                continue;
            }
            if (!isalnum(s[j])) {
                j--;
                continue;
            }

            // Convert characters to lowercase for comparison
            char a = tolower(s[i]);
            char b = tolower(s[j]);

            // If the characters don't match, return false
            if (a != b) {
                return false;
            }

            // Move pointers inward
            i++;
            j--;
        }
        return true;
    }
};
