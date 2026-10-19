#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        // Map mein number ko key aur uska index value ke roop mein store karenge.
        unordered_map<int, int> mpp;

        for (int i = 0; i < nums.size(); i++) {

            // Current number ko target se subtract karke required number nikaalo.
            int complement = target - nums[i];

            // Check karo ki required number pehle se map mein hai ya nahi.
            if (mpp.find(complement) != mpp.end()) {

                // Number mil gaya!
                // mpp[complement] = us number ka purana index.
                // i = current number ka index.
                // Dono indices return kar do.
                return {mpp[complement], i};
            }

            // Agar complement nahi mila, toh current number aur uska index store karo.
            // Example: i = 0, nums[i] = 5
            // mpp[5] = 0;  (key = number, value = index)
            mpp[nums[i]] = i;
        }

        // Agar koi valid pair nahi mila, toh empty vector return karo.
        return {};
    }
};


// We need to return indices, so we use an unordered_map to store each number
// as the key and its index as the value.
// In each iteration, calculate the complement as target - nums[i].
// Check whether this complement already exists in the map.
// If found, return the complement's stored index and the current index i.
// Otherwise, store the current number and its index in the map
// so that it can be used as a complement in future iterations.
// revision done on 19/10/26