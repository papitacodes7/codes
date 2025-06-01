#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        
        // Final answer array, initially sab elements -1 rakhe hain
        vector<int> nge(n, -1);

        // Monotonic stack banayenge — strictly decreasing stack for next greater logic
        stack<int> st;

        // Hum array ko 2 times loop kar rahe hain to simulate circular nature
        for (int i = 2 * n - 1; i >= 0; i--) {

            // ⬇️ Yeh while loop max N times chalega — but overall stack mein N elements se zyada nahi honge
            // Kyuki har element sirf ek baar stack mein push hota hai
            // Jaise ki: kabhi 3 ya 2 ya sirf 1 element ho stack mein — that's why total work across all iterations is O(N)
            while (!st.empty() && st.top() <= nums[i % n]) {
                st.pop(); // Remove chhoti values because woh next greater nahi ban sakti
            }

            // Sirf pehle N iterations mein answer fill karna hai (i < n)
            if (i < n) {
                if (!st.empty()) {
                    nge[i] = st.top(); // Top of stack is next greater
                }
            }

            // Push current element into the stack (i % n for circular array handling)
            st.push(nums[i % n]);
        }

        return nge;
    }
};

int main() {
    Solution obj;
    vector<int> v {5, 7, 1, 2, 6, 0};

    vector<int> res = obj.nextGreaterElements(v);

    cout << "The next greater elements are" << endl;
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    } 
    cout << endl;
}


// LeetCode
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> ngeMap; // Store next greater for each number in nums2
        stack<int> st;

        // Build the map for next greater elements in nums2
        for (int i = nums2.size() - 1; i >= 0; i--) {
            int current = nums2[i];

            // Maintain decreasing stack
            while (!st.empty() && st.top() <= current) {
                st.pop();
            }

            // If stack is empty, no greater element
            if (st.empty()) {
                ngeMap[current] = -1;
            } else {
                ngeMap[current] = st.top();
            }

            st.push(current);
        }

        // Prepare result using the map for elements in nums1
        vector<int> result;
        for (int num : nums1) {
            result.push_back(ngeMap[num]);
        }

        return result;
    }
};




