#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int count = k;   // so first 1 is always valid

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                count++;                 // zero aaya toh count++
            } else {
                if (count < k) return false;  // 1 aaya & zeros kam hain
                count = 0;               // 1 aaya toh zero ka count reset
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 0, 0, 0, 1, 0, 0, 1};
    int k = 2;

    cout << (sol.kLengthApart(nums, k) ? "true" : "false");
    return 0;
}


//Intuition ye hai ki hum consecutive `1`s ke beech **kitne zeros hain** ye track karte hain. Zero aayga toh `count++` krenge, aur jab `1` aayga toh pehle check krenge ki last `1` ke baad zero ka count `k` se kam toh nahi hai. Agar kam hua, toh required distance maintain nahi hua aur answer `false` ho jaata hai. Agar condition satisfy hoti hai, toh naye `1` ke liye zero ka count dubara `0` se shuru kar dete hain. Array ke end tak agar kabhi violation nahi hota, toh answer `true` hota hai.

//Time Complexity: O(n)
//Spave complexity: O(1)

// aaj 22/1/26 ko teeno skip kiye and yehi kiya just..