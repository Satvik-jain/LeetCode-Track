class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int i=0; int j = 0;
        // int max = 0;
        unordered_map <int, int> s;
        int maxe = INT_MIN;
        while(j<n){
            s[fruits[j]]++;
            if (s.size() == 3){
                while(s.size()==3){
                    s[fruits[i]]--;
                    if(s[fruits[i]] == 0){
                        s.erase(fruits[i]);
                    }
                    i++;
                }
            }
            if (maxe < j-i+1) maxe = j-i+1;
            j++;
        }
        return maxe;
    }
};