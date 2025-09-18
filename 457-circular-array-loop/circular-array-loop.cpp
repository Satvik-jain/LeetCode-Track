class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        vector<int> vis(n, 0), path_vis(n, 0), zeros = path_vis;
        for (int i = 0; i < n; i++){
            if (!vis[i]){
                int dir = nums[i]/abs(nums[i]);
                cout << dir << endl;
                path_vis = zeros;
                queue<int> q;
                q.push(i);
                while(!q.empty()){
                    int index = q.front(); q.pop();
                    if (nums[index]*dir < 0 || nums[index] % n == 0) break;
                    if (!vis[index]){
                        int new_index = index+nums[index];
                        if (new_index >= n) new_index %= n;
                        else if (new_index < 0) new_index = n - (abs(new_index)%n);
                        q.push(new_index);
                        vis[index] = 1;
                        path_vis[index] = 1;
                    }
                    else if (path_vis[index]) return true;
                }
            }
        }
        return false;
    }
};