class Solution {
  public:
    int findMin(vector<int> &arr) {
        // Code Here
        int s = 0;
        int n = arr.size();
        int e = arr.size() - 1;
        while(e >= s){
            if (arr[s] <= arr[e]) return arr[s]; // index of min ele
            int mid = (s+e)/2;
            int next = (mid + 1)%n;
            int prev = (mid + n -1) % n;
            if (arr[mid] <= arr[prev] && arr[mid] <= arr[next]){
                return arr[mid];
            }
            if (arr[mid] >= arr[s]) s = mid+1;
            else  e = mid - 1;
        }
        return 0;
    }
};
