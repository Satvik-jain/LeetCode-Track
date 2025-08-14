class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int firstElement = 0;

        unordered_map<int, vector<int>> mpp;


        int n = adjacentPairs.size();

        // vector<int> rec(n+2, 0);

        for (auto i : adjacentPairs){
            // rec[i[0]]++;
            // rec[i[1]]++;
            mpp[i[0]].push_back(i[1]);
            mpp[i[1]].push_back(i[0]);
        }

        for (auto &p : mpp) {
            if (p.second.size() == 1) {
                firstElement = p.first;
                break;
            }
        }


        vector<int> ans; int past = firstElement; int curr = firstElement;
        ans.push_back(firstElement);
        for(int i = 0; i < n; i++){
            int poss1 = mpp[curr][0];
            if (i==0 || i==n){
                ans.push_back(poss1);
                curr = poss1;
                continue;
            }
            int poss2 = mpp[curr][1];
            if (poss1==past){
                poss1 = poss2;
            }
            ans.push_back(poss1);
            past = curr;
            curr = poss1;
        }
        return ans;
    }
};