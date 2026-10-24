#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // Step 1: Make a map and count the frequency of each number from nums.
        unordered_map<int, int> mpp;

        for (int abc : nums) {
            mpp[abc]++;
        }

        // Step 2: Make a vector containing pairs of {number, frequency}
        // from the map, so we can sort these pairs by frequency.
        vector<pair<int, int>> arr;

        for (auto it : mpp) {
            arr.push_back({it.first, it.second});
        }

        // Step 3: Sort the vector by frequency in descending order.
        // Use a custom comparator in sort() when elements must be ordered
        // by a specific property; return a.second > b.second sorts
        // {number, frequency} pairs by frequency in descending order
        // (highest frequency first) so we can extract the top k numbers.
        // Note: This doesn't simply reverse the vector; it sorts by frequency.
        sort(arr.begin(), arr.end(), [](auto a, auto b) {
            return a.second > b.second;
        });

        // Step 4: Make a result vector to store only the top k numbers.
        vector<int> result;

        // Step 5: Take the first k numbers from the sorted vector.
        // Use .first because we need the number, not its frequency.
        for (int i = 0; i < k; i++) {
            result.push_back(arr[i].first);
        }

        // Step 6: Return the k most frequent numbers.
        return result;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    vector<int> result = sol.topKFrequent(nums, k);

    cout << "Top " << k << " frequent elements: ";

    for (int num : result) {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}


// Time Complexity (TC): O(n + m log m)
// - O(n) to count frequencies in the hash map.
// - O(m) to convert the map into a vector of pairs.
// - O(m log m) to sort the pairs.
// - O(k) to collect the top k elements.
// Space Complexity (SC): O(m) auxiliary space for the frequency map, vector of pairs, and result vector.

// Where:
// - n = total number of elements in nums.
// - m = number of distinct elements.
// TC: O(n + m log m) | SC: O(m)


// so basically what we did in this problem is that  first we made a map and counted it's freq from nums vec and then we made a vec which would contain a pair from that map i.e number and freq.. then we do sorting of that vector and add a comparator which reverses the whole thing as we don't want 1,2,3 we want 3,2,1 then we made a result vec which runs till k and pushes the nums which are sorted from that arr into it by pushing back only arr[i].first only

// Use a custom comparator in sort() when elements must be ordered by a specific property; return a.second > b.second; sorts {number, frequency} pairs by frequency in descending order (highest frequency first) so we can extract the top k numbers.