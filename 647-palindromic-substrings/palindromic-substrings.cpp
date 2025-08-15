class Solution {
public:
    bool isPalindrome(const string &s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    void helper(int &ans, string &nums, string &temp, int index) {
        if (index == nums.size()) return;

        // Extend substring one char at a time
        temp.push_back(nums[index]);
        if (isPalindrome(temp)) ans++;
        
        helper(ans, nums, temp, index + 1); // keep extending
        temp.pop_back();                    // backtrack
    }

    void startFromEachIndex(int &ans, string &nums, int start) {
        string temp = "";
        helper(ans, nums, temp, start);      // build substrings from this start
        if (start + 1 < nums.size()) 
            startFromEachIndex(ans, nums, start + 1); // move to next start
    }

    int countSubstrings(string nums) {
        int ans = 0;
        startFromEachIndex(ans, nums, 0);
        return ans;
    }
};
