
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        // First, create an answer vector of the same size as nums.
        // Initialize it with 1s because 1 is the starting product.
        vector<int> answer(nums.size(), 1);

        // PREFIX: Find the product of elements on the LEFT side
        // of each index by traversing from left to right.
        int prefix = 1;

        for (int i = 0; i < nums.size(); i++) {

            // Store the current prefix in the answer array.
            // This gives the product of all numbers BEFORE nums[i].
            answer[i] = prefix;

            // Multiply prefix by the current number so that
            // the product is ready for the next index.
            prefix *= nums[i];
        }

        // SUFFIX: Now calculate the product of elements on the RIGHT
        // side of each index by traversing from right to left.
        int suffix = 1;

        for (int i = nums.size() - 1; i >= 0; i--) {

            // The left product is already stored in answer[i].
            // Multiply it by suffix to get the product of all
            // elements EXCEPT the current number.
            answer[i] *= suffix;

            // Update suffix by multiplying it with the current number.
            // This prepares the right-side product for the next index.
            suffix *= nums[i];
        }

        // Return the final answer array containing the product
        // of all elements except the element at the same index.
        return answer;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 2, 3, 4};

    vector<int> result = sol.productExceptSelf(nums);

    cout << "Product except self: ";

    for (int num : result) {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}


//in this question first we have to find prefix jo milega prefix ko har number se multiply krke from left to right and for suffix it's the same just rigth to left. jab left find krenge toh answer waali array me store krenge so nums[i] = prefix krenge. but when calculating suffix left waala hoggya he so waha pe nums[i] *8 = suffix hoga

// Time Complexity (TC): O(n)
// - Prefix pass takes O(n).
// - Suffix pass takes O(n).
// - Total: O(n) + O(n) = O(n).
// Space Complexity (SC): O(1) auxiliary space, excluding the output array.
// - Only prefix and suffix use constant extra space.
// - The output answer vector takes O(n) space.