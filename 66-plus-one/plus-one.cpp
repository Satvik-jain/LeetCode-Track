class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        // Traverse the digits array from the last digit
        for (int i = n - 1; i >= 0; --i) {
            if (digits[i] < 9) {
                digits[i] += 1; // If the digit is less than 9, simply add 1
                return digits; // Return the result immediately
            }
            digits[i] = 0; // If the digit is 9, set it to 0 and continue
        }
        
        // If we finished the loop, it means all digits were 9
        digits.insert(digits.begin(), 1); // Add a new digit at the beginning
        return digits;
    }
};
