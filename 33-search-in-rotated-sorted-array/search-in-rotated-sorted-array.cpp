class Solution {
  public:
  int bs(int s, int e, int key, vector<int>& arr){
      while(e>=s){
            int mid  = (e+s)/2;
            // int amid = (mid + mine)%n;
            if (arr[mid] == key) return mid;
            else if(arr[mid] > key) e = mid - 1;
            else s = mid + 1;
        }
        return -1;
  }
    int search(vector<int>& arr, int key) {
        // Code Here
        int s = 0;
        int e = arr.size()-1;
        int n = e + 1;
        int mine;
        while(e>=s){
            int mid = (s + e) / 2;
            if (arr[s] <= arr[e]){
                mine = s;
                break;
            }
            int prev = (mid+n-1)%n;
            int next = (mid + 1)%n;
            if (arr[mid] <= arr[prev] && arr[mid] <= arr[next]){
                mine = mid;
                break;
            }
            if (arr[mid] >= arr[s]) s = mid+1;
            else e = mid-1;
        }
        // cout << mine << bs(0, mine-1, key,arr);
        return max(bs(0, mine-1, key,arr), bs(mine, n-1, key,arr));
    }
};