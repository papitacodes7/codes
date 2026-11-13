// Your intuition (refined)
// We use an unordered_set because it stores only unique elements and provides average O(1) lookup. We take three variables: left, right, and longest, where left and right maintain our sliding window and longest stores the maximum length found so far.

// We traverse the string using right and check whether the current character already exists in the set. If it doesn't exist, we insert it and calculate the current window length using right - left + 1, updating longest if necessary.

// If a duplicate is found, we remove the character at left from the set and increment left. We repeat this until the duplicate is removed. Then we insert the current character and continue expanding the window.
// Two small corrections to your explanation
// 1. We don't immediately increase longest when inserting a character. We calculate the window length and update it using max().
// 2. When a duplicate is found, we don't necessarily erase just one character. The inner while loop may remove multiple characters until the duplicate disappears.
// Complexity
// - Time: O(n) average
// - Space: O(min(n, charset))



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        int longest = 0;

        // We use unordered_set because it stores only unique characters
        unordered_set<char> st;

        while (right < s.size()) {

            // Check if the current character is already present in the set
            // If duplicate found, remove the left character and move left forward
            // Repeat until the duplicate is removed
            while (st.find(s[right]) != st.end()) {
                st.erase(s[left]);
                left++;
            }

            // If no duplicate is found, add the current character to the set
            st.insert(s[right]);

            // Calculate the current window length and update the maximum length
            longest = max(longest, right - left + 1);

            // Move right forward to check the next character
            right++;
        }

        return longest;
    }
};

int main() {
    Solution obj;

    string s = "abcabcbb";

    cout << "Input: " << s << endl;
    cout << "Longest substring length: "
         << obj.lengthOfLongestSubstring(s) << endl;

    return 0;
}

// TC: O(n) average
// SC: O(min(n, charset))


//what we did here is took a set because set only stores unique elements and we can use that property where we check if a char already in set or not so what we do is perform sliding window and we make a left and right and longest variable... what we do is check if right is present in set or not if not present we add in set and increase long.. if duplicate found then we erase the left one and add the right one in the set..