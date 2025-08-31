class Solution {
  public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& arr) {
        // code here
        
        int n = arr.size();
        int xmy = 0;
        int temp = 0;
        
        for (int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int k = n*i+j;
                xmy+=(arr[i][j]-(k+1));
                temp+=(arr[i][j]*arr[i][j]-(k+1)*(k+1));
            }
            
        }
        
        int xpy = temp/xmy;

        int x = (xmy+xpy)/2;
        int y = 0.5*(xpy-xmy);
        return {x, y};
    }
};