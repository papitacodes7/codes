/*
DAY 7 — BIG-O MINI-TEST + WEEK 1 DSA REVISION
Date: October 22, 2026

Compile:
g++ -std=c++17 -Wall -Wextra -pedantic "Day7_BigO_Week1_Revision.cpp" -o day7.exe
Run in PowerShell:
.\day7.exe

TODAY'S TASK (~60 minutes)
1. Revise Big-O cheat sheet (10 min).
2. Rewrite Contains Duplicate from memory (15 min).
3. Rewrite Valid Anagram from memory (15 min).
4. Rewrite Two Sum and dry-run it (10 min).
5. Review today's two mistakes (10 min).
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;

/*
BIG-O CHEAT SHEET
O(1)       Constant work
O(log n)   Loop variable multiplies/divides by a constant factor
O(n)       One pass over n items
O(n log n) n work repeated over log n levels/iterations
O(n^2)     Full nested loops or triangular-loop totals

i++ / i += constant -> usually O(n)
i *= 2 / i *= 3     -> usually O(log n)
Two full nested loops -> O(n^2)
Triangular loop       -> O(n^2)
Sequential O(n)+O(n^2) -> O(n^2)
Sequential O(n)+O(log n) -> O(n)

Auxiliary space = extra memory, excluding the input itself.
Fixed number of variables -> O(1) space.
Extra storage growing with n -> O(n) space.
Hash map/set lookup and insertion are O(1) on average.
*/

// Multiplicative loop: O(log n) time.
void multiplicativeLoop(int n) {
    for (int i = 1; i < n; i *= 2) {
        cout << i << " ";
    }
    cout << '\n';
}

// Triangular loop: O(n^2) time.
// Inner-loop executions: 0 + 1 + ... + (n-1) = n(n-1)/2.
void triangularLoop(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            cout << j << " ";
        }
        cout << '\n';
    }
}

// Sequential O(n) loop followed by O(n^2) nested loops.
// Overall time: O(n) + O(n^2) = O(n^2).
void sequentialThenNested(int n) {
    for (int i = 0; i < n; i++) {
        cout << i << " ";
    }
    cout << '\n';

    for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
            cout << "(" << j << "," << k << ") ";
        }
    }
    cout << '\n';
}

// Contains Duplicate
// Average time: O(n). Auxiliary space: O(n).
bool containsDuplicate(const vector<int>& nums) {
    unordered_set<int> seen;
    for (int value : nums) {
        if (seen.find(value) != seen.end()) {
            return true;
        }
        seen.insert(value);
    }
    return false;
}

// Valid Anagram
// Average time: O(n). Auxiliary space: O(k), where k is the number
// of distinct characters. For a fixed alphabet, space is O(1).
bool isAnagram(const string& s, const string& t) {
    if (s.length() != t.length()) {
        return false;
    }

    unordered_map<char, int> freq;
    for (char ch : s) {
        freq[ch]++;
    }
    for (char ch : t) {
        freq[ch]--;
    }
    for (const auto& entry : freq) {
        if (entry.second != 0) {
            return false;
        }
    }
    return true;
}

// Two Sum
// Average time: O(n). Auxiliary space: O(n).
// Map key = number; value = index.
vector<int> twoSum(const vector<int>& nums, int target) {
    unordered_map<int, int> indexByValue;

    for (int i = 0; i < static_cast<int>(nums.size()); i++) {
        int complement = target - nums[i];

        // complement is a NUMBER, not an array index.
        auto it = indexByValue.find(complement);
        if (it != indexByValue.end()) {
            return {it->second, i};
        }

        // Check before storing to avoid using one element twice.
        indexByValue[nums[i]] = i;
    }
    return {};
}

/*
TODAY'S MINI-TEST RESULTS AND MISTAKES

Q1: for (int i = 1; i < n; i *= 2)
Your answer O(log n) — CORRECT.

Q2: Sum a vector passed by reference, using only sum and i.
Your answer O(1) auxiliary space — CORRECT.
Time is O(n), extra space is O(1).

Q3: Triangular loop:
for (int i = 1; i <= n; i++) {
    for (int j = 1; j < i; j++) {
        cout << j;
    }
}
Your answer O(n) — INCORRECT.
Correct: O(n^2), because total work is
0 + 1 + 2 + ... + (n-1) = n(n-1)/2.
It is not exactly n^2 executions, but its Big-O is O(n^2).

Q4: One O(n) loop followed by two nested O(n) loops.
Your answer O(n^2) — CORRECT.
O(n) + O(n^2) = O(n^2).

Q5: Optimized Two Sum.
Your answer O(n) time, O(1) space — PARTLY INCORRECT.
Correct: O(n) average time, O(n) auxiliary space.
The map may store up to n number/index entries.

FINAL DAY 7 SCORE: 3/5 (60%).

TWO MAIN MISTAKES TO REVISIT:
1. Triangular loop -> O(n^2).
2. Two Sum's map can grow with input size -> O(n) space.

Earlier Round 8 reminder:
sumArray/findMax use O(n) time but O(1) auxiliary space because they
use a fixed number of extra variables and don't copy the input.
*/

int main() {
    vector<int> duplicateExample = {1, 2, 3, 1};
    vector<int> twoSumExample1 = {2, 7, 11, 15};
    vector<int> twoSumExample2 = {3, 2, 4};

    cout << boolalpha;
    cout << "=== Day 7 Big-O + Week 1 DSA Revision ===\n\n";

    cout << "Multiplicative loop (n=10): ";
    multiplicativeLoop(10);

    cout << "\nTriangular loop (n=4):\n";
    triangularLoop(4);

    cout << "\nContains Duplicate [1,2,3,1]: "
         << containsDuplicate(duplicateExample) << '\n';

    cout << "Valid Anagram ('aab', 'baa'): "
         << isAnagram("aab", "baa") << '\n';

    cout << "Valid Anagram ('aab', 'abb'): "
         << isAnagram("aab", "abb") << '\n';

    vector<int> result1 = twoSum(twoSumExample1, 9);
    cout << "Two Sum [2,7,11,15], target 9: ";
    if (result1.size() == 2) {
        cout << "[" << result1[0] << ", " << result1[1] << "]\n";
    } else {
        cout << "No solution\n";
    }

    vector<int> result2 = twoSum(twoSumExample2, 6);
    cout << "Two Sum [3,2,4], target 6: ";
    if (result2.size() == 2) {
        cout << "[" << result2[0] << ", " << result2[1] << "]\n";
    } else {
        cout << "No solution\n";
    }

    cout << "\nRewrite all three DSA solutions from memory for practice.\n";
    return 0;
}
