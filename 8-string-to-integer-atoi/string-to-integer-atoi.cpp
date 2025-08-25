class Solution {
public:
    int myAtoi(string s) {
        int maxe = INT_MAX, mine = INT_MIN;
        int i = 0;
        int j = 0;
        bool sign_change = false;
        bool leading = true;

        while(s[j] == ' '){
            i++; j++;
        }

        if (s[j] == '-'){
            sign_change = true;
            j++;
            i++;
        }

        else if (s[j] == '+'){
            i++;
            j++;
        }

        long long num = 0;

        while(j < s.length()){
            if (!isdigit(s[j])){
                break;
            }
            else{
                long long digit = s[j]-'0';
                num = num*10 + digit;
                if (sign_change && num*-1 <= INT_MIN) return INT_MIN;
                if (num > INT_MAX) return INT_MAX;
                cout << num << endl;
                j++;
            }
        }


        return (sign_change) ? -1*num : num;
    }
};