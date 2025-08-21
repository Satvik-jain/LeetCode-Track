/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int ans = 0;
        Employee* start;
        unordered_map<int, Employee*> mpp;
        for(auto i : employees){
            mpp[i->id] = i;
            if (i->id == id){
                start = i;
            }
        }
        ans += start->importance;
        queue<Employee*> q;
        q.push(start);
        while(!q.empty()){
            auto i = q.front();
            q.pop();
            for (int j : i->subordinates){
                auto sub = mpp[j];
                ans+=sub->importance;
                q.push(sub);
            }
        }
        return ans;
    }
};