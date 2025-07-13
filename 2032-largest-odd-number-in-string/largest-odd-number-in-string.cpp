class Solution {
public:
    string largestOddNumber(string num) {
        int l = num.size();
        int index = -1;
        for(int i = l-1; i >= 0; i--){
            int value = num[i] - '0';
            if (value%2 == 0) continue;
            else{
                index = i;
                break;
            }
        }
        string ans;
        if (index==-1) return "";
        else{
            for (int i = 0; i < index+1; i++){
                ans+=num[i];
            }
        }
        return ans;
    }
};