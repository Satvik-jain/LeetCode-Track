class Solution {
public:
    bool isSubsequence(string a, string b) {
        int n = a.size();
        int m = b.size();
        // if (n == 0){
        //     return 1;
        // }
        // if (){
        //     return 0;
        // }
        vector<vector<int>> t(n+1, vector<int>(m+1, 0));
        for (int i = 1; i < n+1; i++){
            for (int j = 1; j < m+1; j++){
                if (a[i-1] == b[j-1]){
                    t[i][j]=1+t[i-1][j-1];
                }
                else{
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
                }
            }
        }
        return a.size()==t[n][m] ? 1 : 0; 
    }
};