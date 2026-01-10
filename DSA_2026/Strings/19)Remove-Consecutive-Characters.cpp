class Solution {
public:
    string removeConsecutiveCharacter(string s) {
        if (s.empty()) {
            return s;
        }

        string result;
        result.push_back(s[0]);

        for (int i = 1; i < s.length(); i++) {
            if (s[i] != s[i - 1]) {
                result.push_back(s[i]);
            }
        }

        return result;
    }
};


We start by handling the empty string case. Then we add the first character to the result and iterate through the string from index 1. A character is appended only if it is different from the previous one, effectively removing consecutive duplicates.

Time Complexity: O(n)
Space Complexity: O(n)We start by handling the empty string case. Then we add the first character to the result and iterate through the string from index 1. A character is appended only if it is different from the previous one, effectively removing consecutive duplicates.

Time Complexity: O(n)
Space Complexity: O(n)