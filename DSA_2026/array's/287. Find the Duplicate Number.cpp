#include <vector>
#include <unordered_map>
using namespace std;


// Find the Duplicate Number


// Approach 1: Using unordered_map

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> mpp;

        for (int i = 0; i < nums.size(); i++) {
            mpp[nums[i]]++;
        }

        for (auto it : mpp) {
            if (it.second > 1) {
                return it.first;
            }
        }

        return -1;
    }
};

// map me key value jese store hota
// he and value pair > 1 hogi toh key answer hoga.


// Approach 2: Floyd's Cycle Detection

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        // move fast and slow pointers until they meet..
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        // as soon as they meet, move both pointers at same speed until they meet again..
        slow = nums[0];

        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};

// slow and fast ko one jump and 2 jump jese chala and fir jab dono same ho jaaye toh slow ko reset krde and fir slow and fast ko same speed se chala jaha pe meet honge waha ka slow return krde.


// Approach 1:
// Time Complexity: Average O(n)
// Space Complexity: O(n)

// Approach 2:
// Time Complexity: O(n)
// Space Complexity: O(1)