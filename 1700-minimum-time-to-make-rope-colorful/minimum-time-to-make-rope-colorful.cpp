class Solution {
public:
    int minCost(string colors, vector<int>& t) {

        int sum = accumulate(t.begin(), t.end(), 0);
        int n = colors.size();
        int maxe = t[0];
        int temp = 0;
        char prev = colors[0]; char curr;

        for (int i = 0; i < n; i++){
            curr = colors[i];
            if (prev!=curr){
                temp += maxe;
                prev = curr;
                maxe = t[i];
            }
            if (t[i] >= maxe && prev == curr){
                maxe = t[i];
            }
        }
        cout << sum << " " << temp;
        return sum - temp - maxe;
    }
};