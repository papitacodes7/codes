class Solution {
  public:
    string smallestWindow(string &s, string &p) {

        // If pattern is bigger than string, answer is impossible
        if (p.size() > s.size()) return "";

        // need[]  -> frequency of characters required from p
        // window[]-> frequency of characters in current window of s
        vector<int> need(26, 0), window(26, 0);

        // Fill the need array using pattern string
        for (char c : p) {
            need[c - 'a']++;
        }

        // required = number of unique characters in p
        int required = 0;
        for (int i = 0; i < 26; i++) {
            if (need[i] > 0) required++;
        }

        // formed = how many unique characters
        // have met their required frequency in current window
        int formed = 0;

        // Two pointers for sliding window
        int l = 0, r = 0;

        // To store best answer
        int minLen = INT_MAX;
        int start = 0;

        // Expand the window by moving right pointer
        while (r < s.size()) {

            char curr = s[r];
            window[curr - 'a']++;   // include current character in window

            // If current character count matches required count
            // then one required character is satisfied
            if (need[curr - 'a'] > 0 &&
                window[curr - 'a'] == need[curr - 'a']) {
                formed++;
            }

            // Try to shrink the window when it becomes valid
            while (l <= r && formed == required) {

                // Update the minimum window if smaller one is found
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }

                // Remove the leftmost character from window
                char leftChar = s[l];
                window[leftChar - 'a']--;

                // If removing this character makes window invalid
                if (need[leftChar - 'a'] > 0 &&
                    window[leftChar - 'a'] < need[leftChar - 'a']) {
                    formed--;
                }

                // Move left pointer forward to shrink window
                l++;
            }

            // Move right pointer forward to expand window
            r++;
        }

        // If no valid window found
        if (minLen == INT_MAX) return "";

        // Return the smallest window substring
        return s.substr(start, minLen);
    }
};


This problem is solved using the sliding window technique with two pointers. We maintain two frequency arrays: one (need) to store the required frequency of each character from string p, and another (window) to store the frequency of characters in the current window of string s. We expand the window by moving the right pointer and update the window array; whenever a character’s frequency in the window becomes equal to its required frequency, we increase a counter (formed). When formed becomes equal to the number of unique characters required (required), the window is valid, meaning it contains all characters of p with correct frequencies. At this point, we try to shrink the window from the left to minimize its size while keeping it valid, updating the minimum-length answer whenever possible. If shrinking causes any required character’s frequency to drop below what is needed, the window becomes invalid and we stop shrinking, then continue expanding again. If no valid window is found, an empty string is returned; otherwise, the smallest valid substring is returned.

Time Complexity: O(n), where n is the length of string s, because each character is visited at most twice by the two pointers.
Space Complexity: O(1), since we use fixed-size frequency arrays of size 26 for lowercase English letters.

// khudka baaki he krna.. stream maintain krne ke liye ai use krliya..