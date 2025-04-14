class Solution {
public:
    string shortestCommonSupersequence(string a, string b) {
        int n = a.size();
        int m = b.size();
        if (n==0 || m==0) return "";
        vector<vector<int>> t(n+1, vector<int>(m+1, 0));
        for (int i = 1; i < n+1; i++){
            for (int j = 1; j < m+1; j++){
                if (a[i-1] == b[j-1]){
                    t[i][j] = t[i-1][j-1] + 1;
                }
                else{
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
                }
            }
        }
        string ans;
        int i = n, j = m;
        while(i>0 || j>0){
            if (j==0){
                ans.push_back(a[i-1]);
                i--;
                continue;
            }
            if (i==0){
                ans.push_back(b[j-1]);
                j--;
                continue;
            }
            if (a[i-1] == b[j-1]){
                ans.push_back(a[i-1]);
                i--;
                j--;
            }
            else{
                if (t[i-1][j] > t[i][j-1]){
                    ans.push_back(a[i-1]);
                    i--;
                }
                else{
                    ans.push_back(b[j-1]);
                    j--;
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};