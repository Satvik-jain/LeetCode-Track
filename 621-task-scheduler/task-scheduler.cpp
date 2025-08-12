class Solution {
public:
    int leastInterval(vector<char>& tasks, int k) {
        // priority_queue<int, char> pq;
        vector<int>record(26, 0);
        int n = tasks.size();
        for (auto i : tasks){
            record[i - 'A']++;
        }
        int count = 0;
        int ele = n;
        while(ele){
            sort(record.begin(), record.end(), greater<int>());
            int limit = k+1;
            for (int i = 0; i < 26; i++){
                 if (limit == 0){
                    break;
                }
                if (record[i]!=0){
                    count++;
                    record[i]--;
                    limit--;
                    ele--;
                }
            }   
            if (limit && ele > 0){
                count += limit;
                limit = 0;
            }
        }
        return count;
    }
};