#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int candidate1 = 0, candidate2 = 0;
        int count1 = 0, count2 = 0;
        
        // Phase 1: Find potential candidates
        for (int x : nums) {
            if (x == candidate1) {
                count1++;
            }
            else if (x == candidate2) {
                count2++;
            }
            else if (count1 == 0) {
                candidate1 = x;
                count1 = 1;
            }
            else if (count2 == 0) {
                candidate2 = x;
                count2 = 1;
            }
            else {
                count1--;
                count2--;
            }
        }
        
        // Phase 2: Verify candidates
        count1 = 0;
        count2 = 0;
        
        for (int x : nums) {
            if (x == candidate1) count1++;
            if (x == candidate2) count2++;
        }
        
        vector<int> res;
        if (count1 > n / 3) res.push_back(candidate1);
        if (count2 > n / 3 && candidate1 != candidate2)
            res.push_back(candidate2);
        
        return res;
    }
};

int main() {
    vector<int> nums = {1, 2, 1, 2, 2, 3, 1};

    Solution sol;
    vector<int> ans = sol.majorityElement(nums);

    cout << "Majority elements (> n/3): ";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}


//If an element appears more than ⌊n/3⌋ times in an array, there can be at most two such elements, because three different numbers each appearing more than n/3 times would exceed the array size. Using this fact, we apply an extended Boyer–Moore Voting Algorithm. In the first pass, we maintain two candidates and their counts. When we see a number equal to a candidate, we increase its count; if a count is zero, we replace that candidate; otherwise, we decrement both counts, which effectively cancels out different elements. After this pass, the candidates are only potential majority elements, not guaranteed. So in the second pass, we re-count the actual frequencies of both candidates and include only those whose counts are greater than ⌊n/3⌋.

// Time Complexity: O(n) — two linear passes over the array
// Space Complexity: O(1) — only a few variables are used (excluding the output vector)

