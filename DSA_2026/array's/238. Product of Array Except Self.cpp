
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        // Step 1: Create an answer vector of the same size as nums,
        // initialized with 1s.
        vector<int> answer(nums.size(), 1);

        // Step 2: Calculate the product of all elements to the LEFT
        // of each index using a running product called prefix.
        int prefix = 1;

        for (int i = 0; i < nums.size(); i++) {

            // Store the product of elements BEFORE the current index.
            answer[i] = prefix;

            // Include the current number for the NEXT index.
            prefix *= nums[i];
        }

        // Step 3: Calculate the product of elements to the RIGHT
        // using a running product called suffix.
        int suffix = 1;

        // Traverse from right to left.
        for (int i = nums.size() - 1; i >= 0; i--) {

            // answer[i] already contains the left product.
            // Multiply it by the right product to get the final answer.
            answer[i] *= suffix;

            // Include the current number for the NEXT index on the left.
            suffix *= nums[i];
        }

        // Step 4: Return the product of all elements except self.
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
