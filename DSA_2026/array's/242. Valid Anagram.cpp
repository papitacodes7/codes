/*
LeetCode 242 — Valid Anagram

LOGIC:
Two strings are anagrams if they contain the same characters
with the same frequencies, even if their order is different.

Example:
s = "aab"
t = "baa"
Answer = true

APPROACH:
1. If lengths differ, they cannot be anagrams.
2. Count each character in s using freq[character]++.
3. Subtract each character in t using freq[character]--.
4. If every final frequency difference is 0, return true.
   Otherwise, return false.
*/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {

        // Step 1: Different lengths mean they cannot be anagrams.
        if (s.length() != t.length()) return false;

        // Step 2: Key = character, value = frequency difference.
        unordered_map<char, int> freq;

        // Step 3: Count each character in the first string.
        for (char it : s) {
            freq[it]++;
        }

        /*
        Example: s = "aab"

        After this loop:
        freq['a'] = 2
        freq['b'] = 1
        */

        // Step 4: Subtract each character in the second string.
        for (char bt : t) {
            freq[bt]--;
        }

        /*
        Example: t = "baa"

        'b': 1 -> 0
        'a': 2 -> 1
        'a': 1 -> 0

        Final differences:
        freq['a'] = 0
        freq['b'] = 0
        */

        // Step 5: Check that every frequency difference is zero.
        for (auto it : freq) {

            // it.first = character (key)
            // it.second = frequency difference (value)

            if (it.second != 0) return false;
        }

        // Step 6: All differences are zero, so they are anagrams.
        return true;
    }
};

int main() {
    Solution sol;

    // Test 1: These strings are anagrams.
    string s = "aab";
    string t = "baa";

    if (sol.isAnagram(s, t)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    // Test 2: Uncomment these lines to test non-anagrams.
    // string s2 = "aab";
    // string t2 = "abb";
    // cout << boolalpha << sol.isAnagram(s2, t2) << endl;
    // Expected output: false

    return 0;
}

/*
DRY RUN 1 — ANAGRAM:
s = "aab", t = "baa"

After counting s:
a = 2, b = 1

After subtracting t:
a = 0, b = 0

All differences are zero -> true.


DRY RUN 2 — NOT ANAGRAM:
s = "aab", t = "abb"

After counting s:
a = 2, b = 1

After subtracting t:
a = 1, b = -1

A difference is non-zero -> false.


TIME COMPLEXITY:
Average O(n), where n is the length of the strings.

SPACE COMPLEXITY:
O(k), where k is the number of distinct characters
stored in the map.
*/