class Solution {
public:
    vector<int> helper(vector<int> arr){
        vector<int> v(arr.size()+1, 1);
        int i = 0, j = 1;
        while(j < arr.size()){
            v[i+1] = arr[i] + arr[j];
            i++;j++;
        }
        return v;
    }
    vector<vector<int>> generate(int n) {
        vector<vector<int>> v;
        vector<int> temp(1, 1);
        v.push_back(temp);
        if (n == 1) return v;
        temp.push_back(1);
        v.push_back(temp);
        if (n==2) return v;
        int i = 3;
        while(i <= n){
            v.push_back(helper(temp));
            i++;
            temp = v[v.size()-1];
        }
        return v;
    }
};