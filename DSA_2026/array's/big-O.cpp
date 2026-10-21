    /*
    BIG-O REVISION NOTES — DAY 6 + ROUND 8
    Topics, examples, mistakes, and solved LeetCode problems.

    Compile:
    g++ "BigO_Day6_Round8_Revision.cpp" -o bigo.exe

    Run in PowerShell:
    .\bigo.exe
    */

    #include <iostream>
    #include <vector>
    #include <string>
    #include <unordered_set>
    #include <unordered_map>
    using namespace std;

    /*
    =========================================================
    1. BIG-O CHEAT SHEET
    =========================================================

    O(1)       Constant time
    O(log n)   Logarithmic time
    O(n)       Linear time
    O(n log n) Linearithmic time
    O(n^2)     Quadratic time

    LOOP PATTERNS:

    i++ or i += constant      -> Usually O(n)
    i *= 2 or i *= 3          -> Usually O(log n)
    Two full nested loops     -> O(n^2)
    Triangular nested loop    -> O(n^2)

    SEQUENTIAL LOOPS:
    Add their complexities and keep the dominant term.

    Example:
    O(n) + O(n^2) = O(n^2)
    O(n) + O(log n) = O(n)

    AUXILIARY SPACE:
    Extra memory used by the algorithm, excluding input storage.

    Fixed number of variables      -> O(1) space
    Copy of n elements              -> O(n) space
    Hash set/map holding n entries  -> O(n) space

    unordered_map and unordered_set operations are O(1)
    on average, but may be slower in the worst case.
    */


    /*
    =========================================================
    2. MULTIPLICATIVE LOOP — O(log n)
    =========================================================
    */

    void multiplicativeLoop(int n) {
        // i becomes 2, 6, 18, 54, ...
        // It is multiplied by 3 every iteration.
        // Time complexity: O(log n)

        for (int i = 2; i <= n; i *= 3) {
            cout << i << " ";
        }

        cout << '\n';
    }


    /*
    =========================================================
    3. TRIANGULAR LOOP — O(n^2)
    =========================================================
    */

    void triangularLoop(int n) {
        // Inner loop runs:
        // 1 + 2 + 3 + ... + n times.
        //
        // Total = n(n + 1) / 2
        // Time complexity = O(n^2)

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                cout << "*";
            }

            cout << '\n';
        }
    }


    /*
    =========================================================
    4. SEQUENTIAL VS NESTED LOOPS
    =========================================================
    */

    void sequentialAndNestedLoops(int n) {

        // First loop: O(n)
        for (int i = 0; i < n; i++) {
            cout << i << " ";
        }

        cout << '\n';

        // Nested loops: O(n * n) = O(n^2)
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                cout << "(" << j << "," << k << ") ";
            }
        }

        cout << '\n';

        // Overall:
        // O(n) + O(n^2) = O(n^2)
    }


    /*
    =========================================================
    5. CONSTANT AUXILIARY SPACE — O(1)
    =========================================================
    */

    int sumArray(const vector<int>& nums) {

        // nums is passed by reference, so it is not copied.
        // Extra variables: sum and i.
        //
        // Time: O(n)
        // Auxiliary space: O(1)

        int sum = 0;

        for (int i = 0; i < (int)nums.size(); i++) {
            sum += nums[i];
        }

        return sum;
    }


    int findMax(const vector<int>& nums) {

        // Assumes nums is not empty.
        //
        // Time: O(n)
        // Auxiliary space: O(1)

        int maximum = nums[0];

        for (int i = 1; i < (int)nums.size(); i++) {
            if (nums[i] > maximum) {
                maximum = nums[i];
            }
        }

        return maximum;
    }


    /*
    =========================================================
    6. CONTAINS DUPLICATE — unordered_set
    =========================================================

    Time: O(n) average
    Auxiliary space: O(n)

    The set stores values we have already seen.
    If a value is already present, a duplicate exists.
    */

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


    /*
    =========================================================
    7. VALID ANAGRAM — unordered_map
    =========================================================

    Time: O(n) average
    Auxiliary space: O(k), where k is the number of
    distinct characters.

    For a fixed alphabet, such as 26 lowercase letters,
    auxiliary space is O(1).

    Map:
    key   = character
    value = frequency
    */

    bool isAnagram(string s, string t) {

        if (s.length() != t.length()) {
            return false;
        }

        unordered_map<char, int> freq;

        // Count characters in s.
        for (char ch : s) {
            freq[ch]++;
        }

        // Decrease counts using characters in t.
        for (char ch : t) {
            freq[ch]--;
        }

        // All frequencies must be zero.
        for (const auto& entry : freq) {

            if (entry.second != 0) {
                return false;
            }
        }

        return true;
    }


    /*
    Examples:
    "aab" and "baa" -> true
    "aab" and "abb" -> false
    */


    /*
    =========================================================
    8. TWO SUM — unordered_map
    =========================================================

    Time: O(n) average
    Auxiliary space: O(n)

    Map:
    key   = number
    value = index

    Steps:
    1. Calculate complement = target - current number.
    2. Check if complement is already in the map.
    3. If found, return both indices.
    4. Otherwise, store current number and index.

    We check before storing to avoid using the same element twice.
    */

    vector<int> twoSum(const vector<int>& nums, int target) {

        unordered_map<int, int> indexByValue;

        for (int i = 0; i < (int)nums.size(); i++) {

            int complement = target - nums[i];

            // complement is a NUMBER, not an array index.
            auto it = indexByValue.find(complement);

            if (it != indexByValue.end()) {
                return {it->second, i};
            }

            // Key = current number, value = current index.
            indexByValue[nums[i]] = i;
        }

        return {};
    }


    /*
    Examples:

    nums = {2, 7, 11, 15}, target = 9
    Answer: {0, 1}

    nums = {3, 2, 4}, target = 6
    Answer: {1, 2}

    nums = {3, 3}, target = 6
    Answer: {0, 1}
    */


    /*
    =========================================================
    9. MISTAKES FROM YOUR BIG-O QUIZZES
    =========================================================

    MISTAKE 1: TRIANGULAR LOOP
    --------------------------

    You selected:
    "Exactly n^2 times."

    Code:

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            cout << j;
        }
    }

    Correct number of inner-loop executions:

    i = 1 -> 0 times
    i = 2 -> 1 time
    i = 3 -> 2 times
    i = 4 -> 3 times

    Total:

    0 + 1 + 2 + ... + (n - 1)
    = n(n - 1) / 2

    It is NOT exactly n^2 executions.

    However, its Big-O time complexity IS O(n^2).

    Remember:
    Triangular loop -> O(n^2).


    MISTAKE 2: AUXILIARY SPACE OF sumArray
    -------------------------------------

    You answered O(n).

    Correct answer: O(1) auxiliary space.

    Why?

    The function processes n elements, so its TIME complexity is O(n).

    But it only stores:
    - sum
    - i

    These are a fixed number of variables.

    Therefore:
    Time  = O(n)
    Space = O(1)

    Remember:
    Processing n elements does not automatically mean O(n) space.


    MISTAKE 3: AUXILIARY SPACE OF findMax
    -------------------------------------

    You answered O(n).

    Correct answer: O(1) auxiliary space.

    The function stores only:
    - maximum
    - i

    The input vector is passed by reference, so the function
    does not create a copy of the vector.

    Therefore:
    Time  = O(n)
    Space = O(1)


    ROUND 8 SCORE CORRECTION
    ------------------------

    Q1: Multiplicative loop
    Your answer: O(log n)
    Result: Correct

    Q2: Auxiliary space for sumArray
    Your answer: O(n)
    Correct answer: O(1)
    Result: Incorrect

    Q3: Triangular loop
    Your answer: O(n^2)
    Result: Correct

    Q4: Sequential and nested loops
    Your answer: O(n^2)
    Result: Correct

    Q5: Auxiliary space for findMax
    Your answer: O(n)
    Correct answer: O(1)
    Result: Incorrect

    FINAL SCORE: 3/5 = 60%

    The earlier score summary mistakenly said 4/5.
    Your recorded answers show that the correct score is 3/5.

    MAIN LESSON:
    Time complexity measures the work performed.
    Auxiliary space measures the extra memory used.
    */


    /*
    =========================================================
    10. QUICK COMPLEXITY TABLE
    =========================================================

    Code pattern                              Complexity

    One constant operation                    O(1)

    One loop from 0 to n                      O(n)

    Loop where i *= 2                         O(log n)

    Two full nested loops                     O(n^2)

    Triangular loop                           O(n^2)

    Sequential O(n) and O(n^2) blocks         O(n^2)

    Sequential O(n) and O(log n) blocks       O(n)

    O(n) loop with O(log n) inner loop        O(n log n)

    Fixed number of extra variables           O(1) space

    Copy of n elements                        O(n) space

    Hash set/map storing up to n elements     O(n) space
    */


    /*
    =========================================================
    11. MAIN FUNCTION — TEST EXAMPLES
    =========================================================
    */

    int main() {

        vector<int> nums1 = {1, 2, 3, 1};
        vector<int> nums2 = {2, 7, 11, 15};
        vector<int> nums3 = {3, 2, 4};

        cout << boolalpha;

        cout << "Multiplicative loop, n = 30:\n";
        multiplicativeLoop(30);

        cout << "\nSum of nums1: "
            << sumArray(nums1) << '\n';

        cout << "Maximum of nums1: "
            << findMax(nums1) << '\n';

        cout << "Contains duplicate? "
            << containsDuplicate(nums1) << '\n';

        cout << "Is 'aab' an anagram of 'baa'? "
            << isAnagram("aab", "baa") << '\n';

        cout << "Is 'aab' an anagram of 'abb'? "
            << isAnagram("aab", "abb") << '\n';

        vector<int> result1 = twoSum(nums2, 9);

        cout << "Two Sum indices for target 9: ";

        if (result1.size() == 2) {
            cout << result1[0] << ", " << result1[1] << '\n';
        } else {
            cout << "No solution\n";
        }

        vector<int> result2 = twoSum(nums3, 6);

        cout << "Two Sum indices for target 6: ";

        if (result2.size() == 2) {
            cout << result2[0] << ", " << result2[1] << '\n';
        } else {
            cout << "No solution\n";
        }

        return 0;
    }
