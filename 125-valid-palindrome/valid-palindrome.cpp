class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        while(j > i){
            char a = tolower(s[i]);
            char b = tolower(s[j]);
            int an = a - 'a';
            int bn = b - 'a';
            cout << "a : " << a << ", b : " << b << ", an : " << an << ", bn : " << bn << endl;
            if ((an < 0 || an > 25) && (an < -49 || an > -40)){
                i++;
                continue;
            }
            if ((bn < 0 || bn > 25) && (bn < -49 || bn > -40)){
                j--;
                continue;
            }
            if (a!=b){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};